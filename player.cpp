#include "player.h"

Player::Player(int _x, int _y, int _dir)
{
  x = _x;
  tx = _x;
  y = _y;
  ty = _y;
  dir = _dir;
  mlcounter = 0;
  mrcounter = 0;
  moving = 0;
}

int Player::getY(){return y;}
int Player::getTy(){return ty;}
int Player::getX(){return x;}
int Player::getTx(){return tx;}
int Player::getDir(){return dir;}
int Player::getMLcounter(){return mlcounter;}
int Player::getMRcounter(){return mrcounter;}
int Player::getMoving(){return moving;}

void Player::setY(int i){y = i;}
void Player::setTy(int i){ty = i;}
void Player::setX(int i){x = i;}
void Player::setTx(int i){tx = i;}
void Player::setDir(int i){dir = i;}
void Player::setMRcounter(int i){mrcounter = i;}
void Player::setMLcounter(int i){mlcounter = i;}
void Player::setMoving(int i){moving = i;}

void Player::decreaseMLcounter(){mlcounter--;}
void Player::decreaseMRcounter(){mrcounter--;}
void Player::resetcounters(){ mlcounter = 0; mrcounter = 0; }
