#include <bits/stdc++.h>
#include "GameBoard.hpp"
using namespace std;
int main(){
    int n = 8;
    GameBoard* board = new GameBoard(n);
    board->InitFunction();
    int turn = 1;
    srand(time(0));
    while(turn==1){
        int sz = board->playerlist.size();
        while(sz-- > 0){
            auto player = board->playerlist.front();
            board->playerlist.pop();
            int chance = board->dice->rollDice();
            int newPos = (player->position)+chance;
            if(newPos==(board->size*board->size -1)){
                cout<<player->name<<" wins the game.\n";
                break;
            } 
            int laddercheck = board->checkLadder(newPos);
            int snakecheck = board->checkSnake(newPos);
            if(laddercheck!=-1)board->checkPosition[player->id] = laddercheck;
            else if(snakecheck!=-1)board->checkPosition[player->id] = snakecheck;
            else {
                board->checkPosition[player->id] = newPos;
            }
            player->position = board->checkPosition[player->id];
            board->playerlist.push(player);
            board->DisplayBoard();
            cout<<"\n=================================================================\n";
            srand(time(0));
        }
        cout<<"\nGo for the next turn enter 1:";       
        cin>>turn;
    }
    return 0;
}