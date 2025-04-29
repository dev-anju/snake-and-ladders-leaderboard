#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Gamer {
public:
  string name;
  int cell;
  int score;

  Gamer(string playerName) : name(playerName), cell(0), score(0) {}

  void moveTo(int steps) {
    cell += steps;
    if (cell > 100)
      cell = 100;
    score += steps;
  }
};

class GameBoard {
private:
  map<int, int> snakes;
  map<int, int> ladders;

public:
  GameBoard() {
    snakes = {{16, 6},  {47, 26}, {49, 11}, {56, 53}, {62, 19},
              {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78}};
    ladders = {{1, 38},  {4, 14},  {9, 31},  {21, 42}, {28, 84},
               {36, 44}, {51, 67}, {71, 91}, {80, 100}};
  }

  int goTo(int cell) {
    if (snakes.count(cell)) {
      cout << " Bitten by a snake! Sliding to " << snakes[cell] << "...\n";
      return snakes[cell];
    }
    if (ladders.count(cell)) {
      cout << " Found a ladder! Climbing to " << ladders[cell] << "!\n";
      return ladders[cell];
    }
    return cell;
  }
};

class Die {
public:
  int throwDie() { return rand() % 6 + 1; }
};