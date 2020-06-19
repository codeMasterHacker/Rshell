#include "Or.hpp"

Or::Or() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool Or::execute()
{
	if (!leftConnector->execute())
        {
            rightConnector->execute();
            return false; //left failed, ergo return false;
        }
        else
            return true;
}
