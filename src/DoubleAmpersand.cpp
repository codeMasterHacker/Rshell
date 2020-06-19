#include "DoubleAmpersand.hpp"

DoubleAmpersand::DoubleAmpersand() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool DoubleAmpersand::execute()
{
	if (leftConnector->execute())
	{
            rightConnector->execute();
            return true;
	}
        else
            return false;
}
