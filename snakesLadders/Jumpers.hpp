#include <bits/stdc++.h>
using namespace std;
class Jumpers {
    public:
        bool type;
        int start;
        int end;
        Jumpers(int start,int end,bool type){
            this->type = type;
            this->start = start;
            this->end = end;
        }
};