#ifndef TestCommand_hpp
#define TestCommand_hpp
#include "Connector.hpp"

class TestCommand : public Connector
{
public:
    TestCommand();
    virtual bool execute();
};
#endif
