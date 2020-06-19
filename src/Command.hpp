#ifndef Command_hpp
#define Command_hpp
#include "Connector.hpp"

class Command : public Connector
{
    
public:
    Command();
    virtual bool execute();
};
#endif
