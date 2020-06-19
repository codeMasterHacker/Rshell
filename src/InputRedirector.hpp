#ifndef InputRedirector_hpp
#define InputRedirector_hpp
#include "Connector.hpp"

class InputRedirector : public Connector
{
public:
    InputRedirector();
    virtual bool execute();
};
#endif
