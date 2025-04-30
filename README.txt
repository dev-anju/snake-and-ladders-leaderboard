Project Title : Snake and Ladder Game with Points-based Leaderboard

Project Objective 
To build a multiplayer Snake and Ladder game with a scoring system that updates a live leaderboard. The goal is to use clean object-oriented design and structure the code well using low-level design principles, while adding competitive scoring rules.

How to Run ?
1. Compile code using this command
g++ -std=c++17 main.cpp -o app
2. Run the compiled code using this command
./app

Game Rules
1. Players take turns rolling a die.
2. On landing on Ladders Move up, gain 10 points, Snakes Slide down, lose 10 points.
3. First to reach cell 100 wins the game.
4. The scoreboard updates in real-time, ranking players by score.

Key Features
1. Turn-based multiplayer Snake and Ladder game with dynamic board setup .
2. Object-oriented design with clean separation of concerns (Game, Gamer, Board, Dice, etc.) .
3. Customizable scoring rules (+10 for ladders, -10 for snakes, etc .) that influence gameplay strategy .
4. Real-time score updates and a persistent leaderboard ranking players by performance.

Built with ❤ by Anjali and Charishma