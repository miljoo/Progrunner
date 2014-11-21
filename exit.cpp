#include "exit.h"

Exit::Exit(int _x, int _y){
  x = _x;
  y = _y;
}

int Exit::playerOnExit(Player player){
  if(player.getX() == x && player.getY() == y){
    return 1;
  }else{
    return 0;
  }
}

void Exit::setX(int i){x = i;}
void Exit::setY(int i){y = i;}

int Exit::getX(){return x;}
int Exit::getY(){return y;}
