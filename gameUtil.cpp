#include "gameUtil.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int GameUtil::compute(Square* square, Player* player){
  double chi = player->getChi();
  double weight = player->getWeight();
  double teleporterEnergy = square->getTeleporterEnergy();
  double cannonPowder = square->getCannonPowder();
  double teleporterCompute = 0.0;

for(int i = 0; i <= chi; i=i+1){
 teleporterCompute += sqrt(chi * i * teleporterEnergy);
 }
    teleporterCompute *= (1.0/(1.0 + chi));

    double cannonCompute = ((pow(((pow(cannonPowder, 1.7))/(pow(weight, 1.5))), 2.0))/9.8);

return std::max((cannonCompute > teleporterCompute ? cannonCompute : teleporterCompute), 1.0);
}


bool GameUtil::isValidPath(std::vector<int>& path, Player* player, Game* game){

    std::vector<Square*> b = game->getBoard();
    if(path.at(0) != 0 || path.at(path.size()-1) != b.size()-1){
            return false;
        }
    int y = 0;
    int x = y+1;
    while(x<path.size()){

        if(path.at(y) >= path.at(x)){
            return false;
        }
        if(compute(b[path[y]], player) < path.at(x) - path.at(y)){
            return false;
        }
          x++;
          y++;
    }
 return true;
}

int GameUtil::shortestPathDistance(Game* game, Player* player){



    /*int counter = 0;
    int subCount = 0;
std::vector<Square*> b = game->getBoard();
int sizeOfArray = b.size();
    for(int i = 0; i<sizeOfArray; i++){
       double biggest = compute(b[i], player);
       double count1 = sizeOfArray - biggest;
       subCount+= 1;
       if(count1 <= 0 )
       }
    }*/

  return -1;
}
