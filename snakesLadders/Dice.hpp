#include <bits/stdc++.h>
using namespace std;
class Dice {
    private:
        int num_of_dice;
    public:
        Dice(int num_of_dice){
            this->num_of_dice = num_of_dice;
        }
        int rollDice(){
            return ((rand()%6)*num_of_dice)+(num_of_dice);
        }
};