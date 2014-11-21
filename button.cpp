#include "button.h"

    Button::Button(int _x, int _y, char _color, list<pair<int, int> > _gates){
      x = _x;
      y = _y;
      color = _color;
      gates = _gates;
    }
    int Button::playerOnButton(Player player){
      if(player.getX() == x && player.getY() == y){
        return 1;
      }
      else{
        return 0;
      }
    }
    void Button::toggleWalls(Level &level){
      int x;
      int y;
      for(list<pair<int, int > >::iterator lit = gates.begin(); lit != gates.end(); lit++){
        x = (*lit).first;
        y = (*lit).second;
        if(level.gmap[y][x] == 1){
          level.gmap[y][x] = 0;
        }else if(level.gmap[y][x] == 0){
          level.gmap[y][x] = 1;
        }
      }
    }

    void Button::setX(int i){x = i;}
    void Button::setY(int i){y = i;}
    void Button::setColor(char c){color = c;}

    list<pair<int, int> > Button::getList() {return gates;}
    int Button::getX(){return x;}
    int Button::getY(){return y;}
    char Button::getColor(){return color;}
