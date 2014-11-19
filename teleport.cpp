#include "teleport.h"

  Teleport::Teleport(int _x, int _y){
    x = _x;
    y = _y;
  }

	int Teleport::playerOnTP(Player &player){
		if(player.getX() == x && player.getY() == y){
      return 1;
    }else{
      return 0;
    }
	}

	void Teleport::setTPLink(Teleport &tp){
		tx = tp.getX();
		ty = tp.getY();
		tp.setTx(x);
		tp.setTy(y);
	}

  int Teleport::getX(){ return x;}
  int Teleport::getY(){ return y;}
  int Teleport::getTx(){ return tx;}
  int Teleport::getTy(){ return ty;}
  void Teleport::setX(int i){ x = i;}
  void Teleport::setY(int i){ y = i;}
  void Teleport::setTx(int i){ tx = i;}
  void Teleport::setTy(int i){ ty = i;}
