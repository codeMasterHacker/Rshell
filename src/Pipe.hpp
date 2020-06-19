#ifndef Pipe_hpp
#define Pipe_hpp
#include "Connector.hpp"

class Pipe : public Connector
{
public:
    Pipe();
    virtual bool execute();
};
#endif
