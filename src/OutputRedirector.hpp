#ifndef OutputRedirector_hpp
#define OutputRedirector_hpp
#include "Connector.hpp"

class OutputRedirector : public Connector
{
public:
    OutputRedirector();
    virtual bool execute();
};
#endif
