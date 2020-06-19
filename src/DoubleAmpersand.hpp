#ifndef DoubleAmpersand_hpp
#define DoubleAmpersand_hpp
#include "Connector.hpp"

class DoubleAmpersand : public Connector
{
    public:
        DoubleAmpersand();
        virtual bool execute();
};
#endif
