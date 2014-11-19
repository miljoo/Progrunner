#include "logic.h"

void turnPlayer(Player &player, int _turn){

  int tmp = player.getDir();

  //turn right
  if(_turn == 0){
    switch(tmp){
      case 8:
        player.setDir(6);
      break;
      case 6:
        player.setDir(2);
      break;
      case 2:
        player.setDir(4);
      break;
      case 4:
        player.setDir(8);
      break;
    }
    //turn left
  }else if(_turn == 1){
    switch(tmp){
      case 8:
        player.setDir(4);
      break;
      case 6:
        player.setDir(8);
      break;
      case 2:
        player.setDir(6);
      break;
      case 4:
        player.setDir(2);
      break;
    }
  }
}

void movePlayer(Player &player){
  if(player.getDir() == 8){
    player.setY(player.getY() + 1);
	}else if(player.getDir() == 6){
		player.setX(player.getX() + 1);
	}else if(player.getDir() == 2){
		player.setY(player.getY() - 1);
	}else if(player.getDir() == 4){
		player.setX(player.getX() - 1);
	}
}

int checkPlayerFront(Player player, Level level){
  int tmp = player.getDir();
  switch(tmp){
    case 8:
      if(!level.gmap[player.getY() + 1][player.getX()] == 0){
        return 1;
      }
    break;
    case 6:
      if(!level.gmap[player.getY()][player.getX() + 1] == 0){
        return 1;
      }
    break;
    case 2:
      if(!level.gmap[player.getY() - 1][player.getX()] == 0){
        return 1;
      }
    break;
    case 4:
      if(!level.gmap[player.getY()][player.getX() - 1] == 0){
        return 1;
      }
    break;
  }
}


void checkMagnet(Player &player, Level level){
  int dir = player.getDir();
	int x = player.getX();
	int y = player.getY();

	if(dir == 2 || dir == 8){
		if(level.gmap[y][x + 1] == 2){
			if(dir == 2 && player.getMLcounter() == 0){
				player.setMLcounter(3);
			}else if(dir == 8 && player.getMRcounter() == 0){
				player.setMRcounter(3);
			}
		}
		if(level.gmap[y][x - 1] == 2){
			if(dir == 2 && player.getMRcounter() == 0){
				player.setMRcounter(3);
			}else if(dir == 8 && player.getMLcounter() == 0){
				player.setMLcounter(3);
			}
		}
    if(level.gmap[y][x + 1] == 2 && level.gmap[y][x - 1] == 2){
			player.setMRcounter(0);
			player.setMLcounter(0);
		}
	}
	else if(dir == 4 || dir == 6){

		if(level.gmap[y + 1][x] == 2){
			if(dir == 6 && player.getMLcounter() == 0){
				player.setMLcounter(3);
			}else if(dir == 4 && player.getMRcounter() == 0){
				player.setMRcounter(3);
			}
		}
		if(level.gmap[y - 1][x] == 2){
			if(dir == 6 && player.getMRcounter() == 0){
				player.setMRcounter(3);
			}else if(dir == 4 && player.getMLcounter() == 0){
				player.setMLcounter(3);
			}
		}
		if(level.gmap[y + 1][x] == 2 && level.gmap[y - 1][x] == 2){
			player.setMRcounter(0);
			player.setMLcounter(0);
		}
	}
}


void updateMcounters(Player &player){
  if(player.getMLcounter() > 0){
    player.decreaseMLcounter();
  }
  if(player.getMRcounter() > 0){
    player.decreaseMRcounter();
  }
}

void drawPlayer(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Player& player){
  int pdir;
  if(player.getDir() == 8){
    pdir = 2;
  }else if(player.getDir() == 4){
    pdir = 3;
  }else if(player.getDir() == 2){
    pdir = 0;
  }else if(player.getDir() == 6){
    pdir = 1;
  }
  tiles.setTextureRect(sf::IntRect(0, TILESIZE*pdir, TILESIZE, TILESIZE)); //viilaa tätä
  tiles.setTexture(tilemap);
  tiles.setPosition(player.getX()*TILESIZE, player.getY()*TILESIZE);
  window.draw(tiles);
}

void drawMap(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window,Level level){
 int i , j;
  for(j = 0 ; j < 10 ; j++){
    for(i = 0; i < 10 ; i++){
      tiles.setTextureRect(sf::IntRect(TILESIZE, (TILESIZE*level.gmap[j][i]), TILESIZE, TILESIZE));
      tiles.setTexture(tilemap);
      tiles.setPosition(i*TILESIZE, j*TILESIZE);
      window.draw(tiles);
    }
  }
}

void drawTP(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Teleport teleport){
  tiles.setTextureRect(sf::IntRect(3* TILESIZE, 0, TILESIZE, TILESIZE));
  tiles.setTexture(tilemap);
  tiles.setPosition(teleport.getX()*TILESIZE, teleport.getY()*TILESIZE);
  window.draw(tiles);
}
