#ifndef Or_hpp
#define Or_hpp
#include "Connector.hpp"

class Or : public Connector
{
public:
    Or();
    virtual bool execute();
};
#endif
