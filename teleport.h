#ifndef TELEPORT_H
#define TELEPORT_H
#include "player.h"

class Teleport{

private:
	int x;
	int y;
	int tx;
	int ty;

public:
  Teleport(int _x, int _y);
  int playerOnTP(Player &player);
  void setTPLink(Teleport &tp);
  int getX();
  int getY();
  int getTx();
  int getTy();
  void setX(int i);
  void setY(int i);
  void setTx(int i);
  void setTy(int i);
};

#endif
