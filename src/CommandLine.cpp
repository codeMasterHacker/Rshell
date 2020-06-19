#include "CommandLine.hpp"

bool CommandLine::isConnector(char* cstring)
{
	if (!(strcmp(cstring, ";")))
            return true;
        else if (!(strcmp(cstring, "&&")))
            return true;
        else if (!(strcmp(cstring, "||")))
            return true;
        else if (!(strcmp(cstring, "|")))
            return true;
        else if (!(strcmp(cstring, ">>")))
            return true;
        else if (!(strcmp(cstring, ">")))
            return true;
        else if (!(strcmp(cstring, "<")))
            return true;
        else if (!(strcmp(cstring, "(")))
            return true;
        else if (!(strcmp(cstring, ")")))
            return true;
        else
            return false;
}



void CommandLine::insertSpace()
{//inserts an element with the value ' ', just before the element pointed to by iter
        cmdList.insert(iter, ' '); //insert a space before
        cmdList.insert(++iter, ' '); //insert a space after
        iter--;
}



void CommandLine::deleteTree(Connector* tree)
{
	if (!tree)
            return;
        
        deleteTree(tree->getLeftConnector());
        deleteTree(tree->getRightConnector());
        
        delete tree;
}



CommandLine::CommandLine() {tree = nullptr; commandLine = nullptr;}



void CommandLine::clearCmdList() {cmdList.clear();}



void CommandLine::array2list(char* userInput)
{
	for (unsigned i = 0; userInput[i] != '\0'; i++)
            cmdList.push_back(userInput[i]);
}



bool CommandLine::insertSpaces()
{
	iter = cmdList.begin();
        unsigned quoteCount = 0, parenthesisCount = 0, bracketCount = 0;
        bool quote = false, hashtag = false;

        while (iter != cmdList.end())
        {
            if (hashtag)
            {
                cmdList.erase(iter);
                iter++;
                continue;
            }

            if (*iter == '\"' || quote)
            {
                if (*iter == '\"')
                {
                    quoteCount++;
                    insertSpace();
                }

                if (!(quoteCount % 2)) //if even
                    quote = false;
                else
                    quote = true;
            }
            else
            {
                switch (*iter)
                {
                    case '(': insertSpace(); parenthesisCount++; break;
                    case ')': insertSpace(); parenthesisCount++; break;
                    case '[': insertSpace(); bracketCount++; break;
                    case ']': insertSpace(); bracketCount++; break;
                    case ';': insertSpace(); break;
                    case '#': hashtag = true; break;
                    default: break;
                }
            }

            if (hashtag)
                cmdList.erase(iter);

            iter++;
        }

        if (!(quoteCount % 2) && !(parenthesisCount % 2) && !(bracketCount % 2))
            return true;
        else
            return false;
}



void CommandLine::list2array()
{
	unsigned i = 0;
        commandLine = new char [cmdList.size()+1];

        for (iter = cmdList.begin(); iter != cmdList.end(); iter++)
        {
            commandLine[i] = *iter;
            i++;
        }

        commandLine[i] = '\0';
}



void CommandLine::parse()
{
	unsigned size = 21, index = 0, quoteCount = 0;
        bool newArrayNeeded = true, quotes = false;
        char** cstringArrayPtr = nullptr;
        
        char* cstring = strtok(commandLine," ");
        while (cstring != nullptr)
        {
            if (isConnector(cstring) && !quotes) //cstring is a connector including ()
            {
                if (cstringArrayPtr != nullptr && !isConnector(*cstringArrayPtr))
                {
                    cstringArrayPtr[index] = nullptr;
                    infixVector.push_back(cstringArrayPtr); //push back the name of the command cstring array
                }
                
                cstringArrayPtr = new char*[2]; //cstringArrayPtr is the name of the connector cstring array
                
                cstringArrayPtr[0] = cstring;
                cstringArrayPtr[1] = nullptr;
                
                infixVector.push_back(cstringArrayPtr); //push back the name of the cstring array with the connector
                
                index = 0;
                newArrayNeeded = true;
            }
            else if (!(strcmp(cstring, "\""))) //cstring is a quote, ergo don't insert the quote (skip)
            {
                quoteCount++;
                
                if (!(quoteCount % 2)) //if even
                    quotes = false;
                else
                    quotes = true;
                
                cstring = strtok(nullptr," ");
                
                continue;
            }
            else if (!(strcmp(cstring, "]")) && !quotes) //cstring is a right bracket, ergo don't insert the right bracket (skip)
            {
                cstring = strtok(nullptr," ");
                continue;
            }
            else if (!(strcmp(cstring, "[")) && !quotes) //cstring is a left bracket
            {
                if (newArrayNeeded)
                {
                    cstringArrayPtr = new char*[size]; //cstringArrayPtr is the name of the array of cstrings
                    newArrayNeeded = false;
                }
                
                if (index < size - 1)
                {
                    char* test = new char[5];
                    test[0] = 't'; test[1] = 'e'; test[2] = 's'; test[3] = 't'; test[4] = '\0';
                    
                    cstringArrayPtr[index] = test; //cstringArrayPtr[index] is a cstring
                    index++;
                }
            }
            else //cstring is a word, such as: echo, ls, cat, test, hello, goodbye, world, ect
            {
                if (newArrayNeeded)
                {
                    cstringArrayPtr = new char*[size]; //cstringArrayPtr is the name of the array of cstrings
                    newArrayNeeded = false;
                }
                
                if (index < size - 1)
                {
                    cstringArrayPtr[index] = cstring; //cstringArrayPtr[index] is a cstring
                    index++;
                }
            }
            
            cstring = strtok(nullptr," ");
        }
        
        if (*cstringArrayPtr != nullptr && !isConnector(*cstringArrayPtr))
        {
            cstringArrayPtr[index] = nullptr;
            infixVector.push_back(cstringArrayPtr); //push the name of the cstring array
        }
}



void CommandLine::postfix()
{
	stack<char**> connectorStack;
        
        for (unsigned i = 0; i < infixVector.size(); i++)
        {
            if (!(strcmp(*infixVector[i], "("))) //*infixVector[i] is a left parentheses
                connectorStack.push(infixVector[i]);
            else if (!(strcmp(*infixVector[i], ")"))) //*infixVector[i] is a right parentheses
            {
                while (!connectorStack.empty() && strcmp(*connectorStack.top(), "(") != 0)
                {
                    postfixVector.push_back(connectorStack.top());
                    connectorStack.pop();
                }
                if (!(strcmp(*connectorStack.top(), "(")))
                    connectorStack.pop();
            }
            else if (isConnector(*infixVector[i])) //*infixVector[i] is a connector
            {
                while (!connectorStack.empty())
                {
                    if (!(strcmp(*connectorStack.top(), "(")))
                        break;
                    else
                    {
                        postfixVector.push_back(connectorStack.top());
                        connectorStack.pop();
                    }
                }
                
                connectorStack.push(infixVector[i]);
            }
            else
                postfixVector.push_back(infixVector[i]);
        }
        
        while(!connectorStack.empty())
        {
            postfixVector.push_back(connectorStack.top());
            connectorStack.pop();
        }
}



void CommandLine::buildTree()
{
	stack<Connector*> connectorStack;
        Connector* left = nullptr; Connector* right = nullptr;
        
        for (unsigned i = 0; i < postfixVector.size(); i++)
        {
            if (isConnector(*postfixVector[i]))
            {
                right = connectorStack.top();
                connectorStack.pop();
                left = connectorStack.top();
                connectorStack.pop();
            }
            
            if (!(strcmp(*postfixVector[i], ";")))
            {
                tree = new SemiColon();
                tree->setRightConnector(right);
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], "&&")))
            {
                tree = new DoubleAmpersand();
                tree->setRightConnector(right);
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], "||")))
            {
                tree = new Or();
                tree->setRightConnector(right);
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], "|")))
            {
                tree = new Pipe();
                tree->setRightConnector(right);
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], ">>")))
            {
                tree = new OutputAppender();
                tree->setArguments(right->getArguments());
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], ">")))
            {
                tree = new OutputRedirector();
                tree->setArguments(right->getArguments());
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], "<")))
            {
                tree = new InputRedirector();
                tree->setArguments(right->getArguments());
                tree->setLeftConnector(left);
                
                connectorStack.push(tree);
            }
            else if (!(strcmp(*postfixVector[i], "test")))
            {
                Connector* testCommand = new TestCommand();
                testCommand->setArguments(postfixVector[i]);
                
                connectorStack.push(testCommand);
            }
            else // *postfixVector[i] is a command or path/file/directory
            {
                Connector* command = new Command();
                command->setArguments(postfixVector[i]);
                
                connectorStack.push(command);
            }
        }
        
        tree = connectorStack.top();
        connectorStack.pop();
}



void CommandLine::execute() {tree->execute();}



void CommandLine::deletion()
{
	infixVector.clear();
        postfixVector.clear();
        cmdList.clear();
        
        delete [] commandLine;
        commandLine = 0;
        
        deleteTree(tree);
        tree = nullptr;
}
