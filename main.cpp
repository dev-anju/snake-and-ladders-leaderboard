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
 bool isSnake(int cell) {
    return snakes.count(cell);
  }

  bool isLadder(int cell) {
    return ladders.count(cell);
  }
};

class Die {
public:
  int throwDie() { return rand() % 6 + 1; }
};

class Scoreboard {
public:
  static void show(const vector<Gamer> &gamers) {
    vector<Gamer> sortedGamers = gamers;
    sort(sortedGamers.begin(), sortedGamers.end(),
         [](const Gamer &a, const Gamer &b) {
           if (a.score == b.score)
             return a.name < b.name;
           return a.score > b.score;
         });

    cout << "\n Scoreboard:\n";
    for (const auto &g : sortedGamers) {
      cout << g.name << " - Score: " << g.score << ", Cell: " << g.cell << endl;
    }
    cout << "------------------------\n";
  }
};

class SnakesAndLadders {
private:
  vector<Gamer> gamers;
  GameBoard board;
  Die die;

public:
  SnakesAndLadders(const vector<string> &names) {
    for (const auto &n : names) {
      gamers.push_back(Gamer(n));
    }
  }

  void play() {
    Gamer *winner = nullptr;

    while (!winner) {
      for (auto &gamer : gamers) {
        cout << gamer.name << ", press 'r' to roll the die: ";
        char ch;
        cin >> ch;
        if (ch != 'r')
          continue;

        int roll = die.throwDie();
        cout << gamer.name << " rolled a " << roll << "\n";

        // Move forward
        gamer.cell += roll;
        if (gamer.cell > 100)
          gamer.cell = 100;

        gamer.score += roll; // Base score from dice roll

        int newCell = board.goTo(gamer.cell);

        if (newCell < gamer.cell) {
          gamer.score -= 10; // Snake penalty
        } else if (newCell > gamer.cell) {
          gamer.score += 10; // Ladder bonus
        }

        gamer.cell = newCell;

        if (gamer.cell == 100) {
          winner = &gamer;
          break;
        }
      }
      Scoreboard::show(gamers);
    }

    cout << "\nCongratulations, " << winner->name<< "! You reached cell 100 and won the game! \n";
  }
};

int main() {
  srand(time(0));
  int numPlayers = 0;
  cout << "Enter number of players: ";
  cin >> numPlayers;

  cout << "Enter " << numPlayers << " player name(s), separated by enter:\n";
  vector<string> names;
  string name;

  for (int i = 0; i < numPlayers; ++i) {
    cin >> name;
    names.push_back(name);
  }

  if (names.size() < 2) {
    cout << "Need at least 2 players to start the game.\n";
    return 0;
  }

  SnakesAndLadders game(names);
  game.play();

  return 0;
}
