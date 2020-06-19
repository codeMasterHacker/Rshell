#include "SemiColon.hpp"

SemiColon::SemiColon() 
{
	leftConnector = nullptr; 
	rightConnector = nullptr; 
	arguments = nullptr;
}



bool SemiColon::execute()
{
	bool left = leftConnector->execute();
        rightConnector->execute();
        return left;
}
