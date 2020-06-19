#ifndef SemiColon_hpp
#define SemiColon_hpp
#include "Connector.hpp"

class SemiColon : public Connector
{ 
public:
    SemiColon();
    virtual bool execute();
};
#endif
