#ifndef EXIT_H
#define EXIT_H
#include "player.h"

class Exit{
  private:
    int x;
    int y;

  public:
    Exit(int _x, int _y);
    int playerOnExit(Player player);

    void setX(int i);
    void setY(int i);

    int getX();
    int getY();
};

#endif
