#ifndef BUTTON_H
#define BUTTON_H
#include <list>
#include <utility>
#include "player.h"
#include "level.h"

using namespace std;

class Button{
  private:
    int x;
    int y;
    //bool activated; //tartteeko tätä?
    char color;
    list <pair<int, int> > gates;


  public:
    Button(int _x, int _y, char _color, list<pair<int, int> > _gates);
    int playerOnButton(Player player);
    void toggleWalls(Level &level);
    list<pair<int, int> > getList();

    void setX(int i);
    void setY(int i);
    void setColor(char c);

    int getX();
    int getY();
    char getColor();

};


#endif
