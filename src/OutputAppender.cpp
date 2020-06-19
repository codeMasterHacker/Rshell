#include "OutputAppender.hpp"

OutputAppender::OutputAppender() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool OutputAppender::execute()
{
	int newOutputFD = open(*arguments, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU); //puts newOutputFD USUALLY to slot 3
        
        if (newOutputFD == -1)
        {
            perror("Output Appending Failed");
            return false;
        }
        else
        {
            int saveStdOut = dup(1); //save stdout
            
            dup2(newOutputFD, 1); //send new fd to slot 1
            
            bool execution = leftConnector->execute(); //execute the command to newOutputFD
            
            dup2(saveStdOut, 1); //restore stdout to slot 1
            
            close(newOutputFD);
            
            if (execution)
                return true;
            else
                return false;
        }
}
