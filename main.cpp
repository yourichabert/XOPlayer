#include <iostream>
#include <string>
#include <sstream>
#include "Morpion.h"

using namespace std;

int main()
{
    //Les positions dans la grille de morpion sont numérotées de 0 à 8 en partant du coin supérieur gauche.
    Morpion game();

    cout << "Please enter moves : " << endl;
    string stringState;
    cin >> stringState;
    GraphNode a = GraphNode(stringState, nullptr);
    short winner = a.giveWinner();
    if (winner == 0) {
        std::cout << "Game not finished or draw !";
    }
    else if (winner == -2) {
        std::cout << "Invalid game ! The players have played twice on the same square !";
    }
    else {
        std::cout << "Player " << winner << " wins !" << endl;
    }
    return 2;
}
