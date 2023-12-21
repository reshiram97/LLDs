#include <bits/stdc++.h>
#include "Dice.hpp"
#include "Player.hpp"
#include "Jumpers.hpp"
using namespace std;
class GameBoard {
    public:
        int size;
        vector<string> board;
        queue<Player*> playerlist;
        vector<Jumpers*> snakes,ladders;
        Dice *dice;
        map<string,int> checkPosition; 
        GameBoard(int size){
            this->size = size;
            board = vector<string>(size*size,".");
        }
        void InitFunction(){
            dice = new Dice(2);
            int num_of_ladders,num_of_snakes;
            int ladders_init[5][3] = {{8,45,1},{2,12,1},{23,60,1},{30,52,1},{19,35,1}};
            int snakes_init[5][3] = {{60,27,0},{50,20,0},{62,2,0},{44,10,0},{30,10,0}};
            for(auto it: ladders_init){
                Jumpers *obj = new Jumpers(it[0],it[1],it[2]);
                board[it[0]] = "LS";
                board[it[1]] = "LE";
                ladders.push_back(obj);
            }
            for(auto it: snakes_init){
                Jumpers *obj = new Jumpers(it[0],it[1],it[2]);
                board[it[0]] = "SS";
                board[it[1]] = "SE";
                snakes.push_back(obj);
            }
            playerlist.push(new Player("Aman","A",0));
            playerlist.push(new Player("Rhea","R",0));
            checkPosition["A"] = 0;
            checkPosition["R"] = 0;
            
        }
        int checkLadder(int currPos){
            for(auto it: ladders){
                if(it->start==currPos)return it->end;
            }
            return -1;
        }
        int checkSnake(int currPos){
            for(auto it: snakes){
                if(it->start==currPos)return it->end;
            }
            return -1;
        }
        void DisplayBoard(){
            
            // Clean Board from Previous Iter
            for(auto &it: board){
                string tmp = it.substr(0,2);
                if(tmp=="LS" || tmp=="SS" || tmp=="LE" || tmp=="SE"){
                    it = tmp;
                } else {
                    it = ".";
                }
            }

            // Update the Board
            for(auto it: checkPosition){
                board[it.second]+=it.first;
            }
            
            int cnt = 0;
            for(int i=0;i<size;i++){
                string st = "";
                for(int j=0;j<size;j++){
                    cout<<board[cnt]<<"\t";
                    cnt++;
                }
                cout<<"\n";
            }
        }
};