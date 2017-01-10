#include "square.h"
#include "game.h"
#include "player.h"
#include "gameUtil.h"
#include <iostream>
#include <vector>
int main(){
  std::vector<Square*> game_board;

  game_board.push_back(new Square(0,0));
  game_board.push_back(new Square(0,0));
  game_board.push_back(new Square(0,0));
  game_board.push_back(new Square(0,0));
  game_board.push_back(new Square(0,0));

  Game* game1 = new Game(game_board);
  Player* player1 = new Player(9, 2);

  std::vector<Square*> board = game1->getBoard();

  GameUtil* util = new GameUtil();

  int maxTravelDistance = util->compute(game_board.at(0), player1);
  std::cout << "max distance: " << maxTravelDistance << std::endl;

  //int length = util->shortestPathDistance(game1, player1);
  //std::cout << "Length of shortest path: " << length << std::endl;

  std::vector<int> path;
  path.push_back(0);
  path.push_back(2);
  path.push_back(3);
  path.push_back(4);
  //path.push_back(4);
for(int i = 0; i<path.size(); i++){
std::cout << "Example path is: " << path[i] << std::endl;
}
  bool valid = util->isValidPath(path, player1, game1);
  std::cout << "Example path is valid (0/1): " << valid << std::endl;

  return 0;
}
