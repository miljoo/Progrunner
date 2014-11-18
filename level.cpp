#include <iostream>
#include "level.h"

using namespace std;

Level::Level(){
  for(int j = 0; j < 10 ; j++){
    for(int i = 0 ; i < 10 ; i++){
      gmap[j][i] = 0;
    }
  }
}

void Level::makeWalls(){
   //make walls for level
  for(int j = 0; j < 10 ; j++){
    for (int i = 0 ; i < 10 ; i++){
      if(j == 0 || j == 9){
        gmap[j][i] = 1;
      }
      if(i == 0 || i == 9){
        gmap[j][i] = 1;
      }
    }
  }
}

void Level::printMap(){
  for(int j = 9; j >= 0 ; j--){
    for (int i = 0 ; i < 10 ; i++){
      if(i == 9){
        cout << gmap[j][i];
         cout << endl;
      }
      else{
        cout << gmap[j][i];
      }
    }
  }
}
