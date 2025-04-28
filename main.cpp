#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

class Player{
    public:
    string name;
    int position;
    int points;
    Player(string playername){
        name = playername;
        position = 0;
        points = 0;
    }
    void move(int steps){
        position+= steps;
        if(position > 100){
            position = 100;
        }
        position+= steps;
    }
};

class Board{
    private:
    map<int, int> snakes;
    map<int, int> ladders;
    public:
        Board(){
            snakes={
                {16,6},{47,26},{49,11},{56,53},{62,19},{64,60},{87,24},{93,73},{95,75},{98,78}
                };
                ladders={
                    {1,38},{4,14},{9,31},{21,42},{28,84},{36,44},{51,67},{71,91},{80,100}
                };
            }
            int checkSnakeOrLadder(int position){
                if(snakes.find(position)!= snakes.end()){
                    cout<< "Oops! Snake bite at" <<position<<". Go down to"<<snakes[position]<<endl;
                    return snakes[position];
                }
                if(ladders.find(position)!=ladders.end()){
                    cout<<"Yay! Ladder climbed at"<<position<<". Go up to"<<ladders[position]<<endl;
                    return ladders[position];
                }
                return position;
            }
        };
class Dice{
    private:
    int roll(){
        return (rand()%6)+1;
    }
};
