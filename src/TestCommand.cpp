#include "TestCommand.hpp"

TestCommand::TestCommand() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool TestCommand::execute()
{
	struct stat sb;
        
        if (!strcmp(arguments[1], "-e")) //checks if the file/directory exists
        {
            if (!stat(arguments[2], &sb))
                return true;
            else
            {
                perror("Stat Failed");
                return false;
            }
        }
        else if (!strcmp(arguments[1], "-f")) //checks if the file/directory exists and is a regular file
        {
            if ((!stat(arguments[2], &sb)) && (sb.st_mode & S_IFREG))
                return true;
            else
            {
                perror("Stat Failed");
                return false;
            }
        }
        else if (!strcmp(arguments[1], "-d")) //checks if the file/directory exists and is a directory
        {
            if ((!stat(arguments[2], &sb)) && (sb.st_mode & S_IFDIR))
                return true;
            else
            {
                perror("Stat Failed");
                return false;
            }
        }
        else //arguments[1] is not a flag, ergo it is a path
        {
            if (!stat(arguments[1], &sb))
                return true;
            else
            {
                perror("Stat Failed");
                return false;
            }
        }
}
