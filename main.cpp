#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include "player.h"
#include "logic.h"
#include "level.h"
#include "teleport.h"

#define WIN_X 800
#define WIN_Y 640

using namespace std;
enum turnDirection {RIGHT, LEFT};

int main(){
  int gameloop = 1;
  int cmd;

  //Init stuff
  Player p(1,1,8);
  Level l;
  l.makeWalls();
  l.gmap[3][2] = 2;
  l.gmap[5][4] = 2;
  l.gmap[6][8] = 2;
  l.gmap[5][6] = 2;
  l.printMap();

  Teleport t1(8,1);
  Teleport t2(1,2);
  t2.setTPLink(t1);

  cout << "TP1:" << " X:" << t1.getX()<< " Y:" << t1.getY() << " TX:" << t1.getTx() << " TY:" << t1.getTy() << endl;
  cout << "TP2:" << " X:" << t2.getX()<< " Y:" << t2.getY() << " TX:" << t2.getTx() << " TY:" << t2.getTy() << endl;

  ifstream ifile;
  sf::RenderWindow window;
  window.create(sf::VideoMode(WIN_X,WIN_Y), "ProgRunner");
  window.setKeyRepeatEnabled(false);
  window.setFramerateLimit(30);
  sf::Texture tilemap;
  sf::Sprite tiles;
  if(!tilemap.loadFromFile("data/Atlas.png")){
    cout << "Error loading tileset" << endl;
  }


  //loop stuff
  while(window.isOpen()){
    sf::Event event;


  while(gameloop){
    sf::sleep(sf::Time(sf::seconds(0.1f)));
      while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
          window.close();
        }
        window.clear();
        if(event.type == sf::Event::KeyPressed){
          if(event.key.code == sf::Keyboard::Up){
            p.setDir(2);
            p.setMoving(1);
          }
          if(event.key.code == sf::Keyboard::Down){
            p.setDir(8);
            p.setMoving(1);
          }
          if(event.key.code == sf::Keyboard::Left){
            p.setDir(4);
            p.setMoving(1);
          }
          if(event.key.code == sf::Keyboard::Right){
            p.setDir(6);
            p.setMoving(1);
          }
        }

        while(p.getMoving()){
          updateMcounters(p);
          if(p.getMLcounter() == 2){
            turnPlayer(p,LEFT);
          }else if(p.getMRcounter() == 2){
            turnPlayer(p,RIGHT);
          }
          checkMagnet(p,l);

          if(t1.playerOnTP(p) || t2.playerOnTP(p)){
            if(t1.playerOnTP(p)){
              p.setX(t1.getTx());
              p.setY(t1.getTy());}
            else{
              p.setX(t2.getTx());
              p.setY(t2.getTy());
            }
          }

          if(!checkPlayerFront(p,l)){
            movePlayer(p);
          }
          else{
            p.setMoving(0);
          }

          drawMap(tilemap, tiles, window ,l);
          //drawExit(tilemap, tiles, window, exit);
          drawTP(tilemap, tiles, window, t1);
          drawTP(tilemap, tiles, window, t2);
          drawPlayer(tilemap, tiles, window, p);
          window.display();
          }
        }
      }
    }
  return 0;
}

