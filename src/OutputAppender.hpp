#ifndef OutputAppender_hpp
#define OutputAppender_hpp
#include "Connector.hpp"

class OutputAppender : public Connector
{
public:
    OutputAppender();
    virtual bool execute();
};
#endif
