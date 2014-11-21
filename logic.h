#ifndef LOGIC_H
#define LOGIC_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "level.h"
#include "teleport.h"
#include "button.h"
#include "exit.h"

#define TILESIZE 64

void turnPlayer(Player &player, int _turn);
void movePlayer(Player &player);
int checkPlayerFront(Player player, Level level);
void checkMagnet(Player &player, Level level);
void updateMcounters(Player &player);
void drawPlayer(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Player& player);
void drawMap(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Level level);
void drawTP(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Teleport teleport);
void drawButton(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Button button);
void drawExit(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Exit exit);

#endif
