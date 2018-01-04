#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "GraphNode.h"

using namespace std;

GraphNode::GraphNode()
{
    //ctor
}

GraphNode::GraphNode(string newStringState, GraphNode* parent)
{
    this->parent=parent;
    this->stringState=newStringState;
}

GraphNode::~GraphNode()
{
    //dtor
}

void GraphNode::constructChildren(list<unsigned short>& availablePositions)
{
    for( unsigned short pos : availablePositions){
        unsigned int newState=state*10+pos;
        std::list<unsigned short> positionsLeft = availablePositions;
        positionsLeft.remove(pos);

        //cout << "New node " << newState << " from node " << state << '\n';

        std::ostringstream ss;
        ss << newState;
        string newStringState = ss.str();
        GraphNode* nextNode = new GraphNode(newStringState, this);
        children.push_back(nextNode);
        nextNode->constructChildren(positionsLeft);

    }

}

void GraphNode::evaluate(bool firstPlayer){
    // Si le noeud est une feuille
    if (children.empty()) {
        evaluation = giveWinner();
    }

    //Si le noeud n'est pas une feuille
    else {

    }

}

short GraphNode::giveWinner()
{
    int currentPlayer=1; //premier joueur

    tableMorpion = vector<vector<short>>(3, vector<short>(3,2));
    //cout << tableMorpion[1][1];

    bool zeroAtTheBeginning=false;

    if (stringState[0]=='0') {
        zeroAtTheBeginning=true;
        if (stringState[1]=='0') {
            return -2;
        }
    }

    unsigned int currentState;
    istringstream(stringState) >> state;
    currentState = state;

    while (currentState > 0) {

        cout << currentPlayer << " plays " << endl;
        unsigned short pos=currentState%10;
        currentState = currentState/10;
        if (tableMorpion[pos/3][pos%3]==2){
            tableMorpion[pos/3][pos%3] = currentPlayer;
            potentialWinner = (currentPlayer == -1) ? -1 : 1;
            if(this->testWin()) {return potentialWinner;}
            currentPlayer = -currentPlayer;
            //cout << "Next player !" << endl;
        }
        else {
            return -2;
        }
    }

    if (zeroAtTheBeginning) {
        cout << currentPlayer << " plays " << endl;
        if (tableMorpion[0][0]==2){
            tableMorpion[0][0] = currentPlayer;
            potentialWinner = (currentPlayer == -1) ? -1 : 1;
            if(this->testWin()) {return potentialWinner;}
        }
        else {
            return -2;
        }
    }
    return 0;
}



bool GraphNode::testWin() {

    bool thereIsAWinner = false;
    // test des lignes
    for (unsigned int i = 0; i < 3; i++) {
        if (tableMorpion[i][0] != 2 && tableMorpion[i][0] == tableMorpion[i][1] && tableMorpion[i][1] == tableMorpion[i][2]) {
            cout << "Full line ! " << endl;
            thereIsAWinner = true;
        }
    }

    // test des colonnes
    for (unsigned int i = 0; i < 3; i++) {
        if (tableMorpion[0][i] != 2 && tableMorpion[0][i] == tableMorpion[1][i] && tableMorpion[1][i] == tableMorpion[2][i]) {
            cout << "Full column ! " << endl;
            thereIsAWinner = true;
        }
    }

    //test des diagonales
    if (tableMorpion[0][0] != 2 && tableMorpion[0][0] == tableMorpion[1][1] && tableMorpion[1][1] == tableMorpion[2][2]){
        cout << "Full diagonal ! " << endl;
        thereIsAWinner = true;
    }
    if (tableMorpion[2][0] != 2 && tableMorpion[2][0] == tableMorpion[1][1] && tableMorpion[1][1] == tableMorpion[0][2]){
        cout << "Full diagonal ! " << endl;
        thereIsAWinner = true;
    }
    return thereIsAWinner;
}
