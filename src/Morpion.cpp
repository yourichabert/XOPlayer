 #include "Morpion.h"
 #include <list>
 #include <string>
 #include <sstream>

 using namespace std;

Morpion::Morpion(unsigned short initialPosition)
{
    std::ostringstream ss;
    ss << initialPosition;
    string stringInitialPosition = ss.str();
    firstNode=GraphNode(stringInitialPosition, nullptr);
    list<unsigned short> availablePositions;
    for(unsigned short i=0; i<9; i++){
        if (i != initialPosition)
            availablePositions.push_back(i);
    }
    firstNode.constructChildren(availablePositions);
}

Morpion::~Morpion()
{
    //dtor
}


