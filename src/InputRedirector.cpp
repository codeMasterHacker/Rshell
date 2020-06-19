#include "InputRedirector.hpp"

InputRedirector::InputRedirector() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool InputRedirector::execute()
{
	int newInputFD = open(*arguments, O_RDONLY); //puts newInputFD USUALLY to slot 3
        
        if (newInputFD == -1)
        {
            perror("Input Redirection Failed");
            return false;
        }
        else
        {
	    int saveStdIn = dup(0); //save stdin USUALLY to slot 4
            
            dup2(newInputFD, 0); //send the new fd to slot 0

	     bool flag = leftConnector->execute(); //execute the command to newInputFD
            
            dup2(saveStdIn, 0); //restore stdin in slot 0
            
            close(newInputFD);
            
            if (flag)
                return true;
            else
                return false;
	}
}
