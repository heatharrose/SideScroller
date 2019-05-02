#include <Arduboy2.h>
#include "World.h"

Arduboy2 arduboy;

#define FRAC_BITS 6
#define playerJump (-100)
#define playerAccel 16
#define negOffset 64
constexpr int playerWidth = 4;
constexpr int playerHeight = 4;
constexpr int groundLevel = (HEIGHT - 9);
constexpr int gravity = 1;
constexpr int gravityFrameRate = 15;
float jumpY = -2;
byte playerFrame = 0;
int playerX = 62;
int playerY = 58;
int playerVelocityY = 0;
int nextPlayerY = (playerY + playerVelocityY);
int nextPlayerYBottom = (nextPlayerY + playerHeight);
int worldX = 0;
char playerYi = playerY;


bool onGround = false;

void setup() 
{
  
 arduboy.begin();
 arduboy.setFrameRate(30);
 arduboy.clear();

}

void loop() 
{
 if(!arduboy.nextFrame())
 return;
//checks button status
arduboy.pollButtons();

  if(arduboy.pressed(LEFT_BUTTON)) {
    if (worldX == 0) { 
      if (playerX > 0) playerX -= 1;  
      }
    else if (worldX == (mapWidth - 16) * 8) { 
      if (playerX > 64 - (playerWidth /2)) { 
        playerX -= 1;
      }
      else {
        worldX -= 1; 
      }
    }
    else {
        worldX -= 1;  
    }

  }

if(arduboy.pressed(RIGHT_BUTTON)) {
  if (worldX == 0) {
    if (playerX < 64 - (playerWidth /2)) {
      playerX += 1;
    } else {
      worldX += 1;
    }
  } else if (worldX == (mapWidth - 16) * 8) {
    if (playerX < 128 - playerWidth) {
      playerX += 1;
    }
  } else {
    worldX += 1;
  }
}

arduboy.clear();


for(uint8_t y = 0; y < mapHeight; ++y) {
  for(uint8_t x = 0; x < mapWidth; ++x) {
    Sprites::drawOverwrite(x * tileWidth, y * tileHeight, ground,getMapTile(x, y));
    
  }
  
//draw player
arduboy.fillRect(playerX, playerY, playerWidth, playerHeight, WHITE);
}
arduboy.display();
}

void startJump() {
  playerVelocityY = playerJump;
  playerFrame = 0;
  playerYi = playerY;

  

if (onGround == true) {
  startJump();
}
}

void start_Gravity() {
  playerFrame = 0;
  playerYi = playerY;
  playerVelocityY = 0;
}
