#include <Arduboy2.h>
#include "World.h"

Arduboy2 arduboy;

int playerX = 62;
int playerY = 58;
int playerVelocityY = 0;

constexpr int playerWidth = 4;
constexpr int playerHeight = 4;
constexpr int groundLevel = (HEIGHT - 9);
constexpr int gravity = 1;
constexpr int gravityFrameRate = 15;

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

  if(arduboy.pressed(LEFT_BUTTON))
  {
    playerX -= 1;
  }
if(arduboy.pressed(RIGHT_BUTTON))
{
  playerX += 1;
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

if(nextPlayerYBottom >= groundLevel)
{
  nextPlayerY = (groundLevel - playerHeight);

  onGround = true;
}
playerY = nextPlayerY;

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
