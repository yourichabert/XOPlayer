#ifndef MORPION_H
#define MORPION_H

#include "GraphNode.h"

class Morpion
{
    public:
        Morpion(unsigned short initialPosition);
        virtual ~Morpion();

    protected:

    private:
        GraphNode firstNode;
};

#endif // MORPION_H
