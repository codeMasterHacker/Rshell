#ifndef Connector_hpp
#define Connector_hpp
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>

class Connector
{
protected:
    Connector* leftConnector;
    Connector* rightConnector;
    char** arguments;
    
public:
    virtual ~Connector(){}
    virtual bool execute() = 0;
    Connector* getLeftConnector() {return leftConnector;}
    Connector* getRightConnector() {return rightConnector;}
    char** getArguments() {return arguments;}
    void setArguments(char** args) {arguments = args;}
    void setLeftConnector(Connector* connector) {leftConnector = connector;}
    void setRightConnector(Connector* connector) {rightConnector = connector;}
};

#endif
