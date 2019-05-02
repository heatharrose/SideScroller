#include <Arduboy2.h>
#include "World.h"

Arduboy2 arduboy;

int playerX = 62;
int playerY = 58;
int playerVelocityY = 0;
int worldX = 0;

constexpr int playerWidth = 4;
constexpr int playerHeight = 4;
constexpr int groundLevel = (HEIGHT - 9);
constexpr int gravity = 1;
constexpr int gravityFrameRate = 15;

bool onGround = false;

bool isVacantSpace(int tile) {
  if (tile == 0) {
    return true;
  }
  return false;
}

bool canMoveLeft() {
  if(playerX == 0) {
    return false;
  } else{
    int absolutePosition = playerX + worldX;
    if (absolutePosition % 8 == 0) {
      uint8_t tile = getMapTile((absolutePosition - 1) / 8, playerY / 8);
      return isVacantSpace(tile);
    } else {
      return true;
    }
  }
  return false;
}

bool canMoveRight() {
  if(playerX == 128 - playerWidth) {
    return false;
  } else {
    int absolutePosition = playerX + worldX + playerWidth;
    if (absolutePosition % 8 == 7) {
      uint8_t tile = getMapTile((absolutePosition + 1) / 8, playerY / 8);
      return isVacantSpace(tile);
    } else {
    return true;
  }
}
return false;
}

void setup() 
{
  
 arduboy.begin();
 arduboy.setFrameRate(30);
 arduboy.clear();

}

void loop() {

  if(!arduboy.nextFrame())
  return;
  //checks button status
  arduboy.pollButtons();

  if(arduboy.pressed(LEFT_BUTTON)) {

    if (canMoveLeft()) {
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

  }

  if(arduboy.pressed(RIGHT_BUTTON)) {

    if (canMoveRight()) {

      if (worldX == 0) { 

        if (playerX < 64 - (playerWidth  / 2)) {  
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
  }
  
if(arduboy.justPressed(A_BUTTON))
{//if player is not jumping
  if(onGround)
  {//make player jump
    playerVelocityY = -2;
    
    onGround = false;

  }
}
//if player is jumping
if(playerVelocityY < 0)
{//start gravity
 if(arduboy.everyXFrames(gravityFrameRate))
 {
  playerVelocityY += gravity;
 }
}

if(playerVelocityY >= 0)
{
  playerVelocityY = gravity;
}
int nextPlayerY = (playerY + playerVelocityY);
int nextPlayerYBottom = (nextPlayerY + playerHeight);

if(nextPlayerYBottom >= groundLevel) {

  nextPlayerY = (groundLevel - playerHeight);
  onGround = true;

}

playerY = nextPlayerY;

arduboy.clear();

// Render the world ..

for(uint8_t y = 0; y < mapHeight; ++y) {

  for(uint8_t x = 0; x < mapWidth; ++x) {


    Sprites::drawOverwrite(x * tileWidth - worldX, y * tileHeight, ground,getMapTile(x, y));
    
  }
  
  //draw player
  arduboy.fillRect(playerX, playerY, playerWidth, playerHeight, WHITE);

  
  }
  arduboy.display();

}
