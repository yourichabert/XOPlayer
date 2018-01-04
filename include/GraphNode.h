#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <list>
#include <string>
#include <vector>

using namespace std;

class GraphNode
{
    public:
        GraphNode();
        GraphNode(string newStringState, GraphNode* parent);
        virtual ~GraphNode();
        void constructChildren(std::list<unsigned short>& availablePositions);
        void evaluate(bool firstPlayer);
        short giveWinner();
        bool testWin();

    protected:

    private:
        GraphNode* parent;
        std::list<GraphNode*> children;
        unsigned int state;
        string stringState;
        short evaluation;
        short potentialWinner;
        vector<vector<short>> tableMorpion;
};

#endif // GRAPHNODE_H
