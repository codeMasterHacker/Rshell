#include "Command.hpp"

Command::Command() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool Command::execute()
{
	int status;
        
        pid_t pid = fork();
        switch (pid)
        {
            case -1: status = 1; perror("Fork Failed"); break;
                
            case 0: //Child process
            {
                if (execvp(*arguments, arguments) < 0) //execute the command
                {
                    perror("Execvp Failed");
                    exit(1);
                }
                else
                    exit(0);

                break;
            }
            
	    //Parent process
	    default: while (wait(&status) != pid); break;
	}

	if (WIFEXITED(status) && !WEXITSTATUS(status))
            return true;
        else
            return false;    
}
