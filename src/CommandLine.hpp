#ifndef CommandLine_hpp
#define CommandLine_hpp
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include "Command.hpp"
#include "TestCommand.hpp"
#include "SemiColon.hpp"
#include "DoubleAmpersand.hpp"
#include "Or.hpp"
#include "Pipe.hpp"
#include "OutputAppender.hpp"
#include "OutputRedirector.hpp"
#include "InputRedirector.hpp"
using namespace std;

class CommandLine
{
private:
    list<char>::iterator iter;
    list<char> cmdList;
    
    vector<char**> infixVector;
    vector<char**> postfixVector;
    
    Connector* tree;
    char* commandLine;
    
    bool isConnector(char* cstring);
    void insertSpace();
    void deleteTree(Connector* tree);
    
   
 
public:
    CommandLine();
    void clearCmdList();
    void array2list(char* userInput);
    bool insertSpaces();
    void list2array();
    void parse();
    void postfix();
    void buildTree();
    void execute();
    void deletion();
};
#endif
