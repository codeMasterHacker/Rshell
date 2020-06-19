#include "Pipe.hpp"

Pipe::Pipe() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool Pipe::execute()
{
	int status, pipeFD[2];
        pid_t pid;
        
        if (pipe(pipeFD) == -1)
        {
            perror("Pipe Failed");
            return false;
        }
        else
        {
            pid = fork();
            switch (pid)
            {
                case -1: perror("Fork Failed"); return false; break;
                    
                case 0: //Child process, which writes to the pipe
                {
                    close(pipeFD[0]); //close the read end of the pipe, since the child only writes to the pipe
                    
                    int stdOut = dup(1); //save stdout
                    
                    dup2(pipeFD[1], 1); //send write end of the pipe to slot 1
                    
                    bool execution = leftConnector->execute();
                    
                    dup2(stdOut, 1); //restore stdout to slot 1
                    
                    close(pipeFD[1]); //close the write end of the pipe
                    
                    if (!execution)
                    {
                        printf("Write Failed\n");
                        exit(1);
                    }
                    else
                        exit(0);
                    
                    break;
                }
                    
                default: //Parent process, which reads from pipe
                {
                    while (wait(&status) != pid);
                    
                    close(pipeFD[1]); //close the write end of the pipe, since the parent only reads from the pipe
                    
                    int stdIn = dup(0); //save stdin
                    
                    dup2(pipeFD[0], 0); //send read end of the pipe to slot 0
                    
                    bool execution = rightConnector->execute();
                    
                    dup2(stdIn, 0); //restore stdout to slot 0
                    
                    close(pipeFD[0]); //close the read end of the pipe
                    
                    if (!execution)
                        printf("Read Failed\n");
                    
                    break;
                }
            }
            
            if (WIFEXITED(status) && !WEXITSTATUS(status))
                return true;
            else
                return false;
        }
}
