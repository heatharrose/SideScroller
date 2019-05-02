#include <Arduboy2.h>
#include "World.h"

Arduboy2 arduboy;

#define playerJump (-100)
byte playerFrame = 0;
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

bool jumpPressed() {
return (arduboy.buttonsState() & (A_BUTTON)) != 0;
}

if(jumpPressed())
{
  startJump();
}

if ((onGround == true) and jumpPressed()) {
  startJump();
}


  
arduboy.clear();

for(uint8_t y = 0; y < mapHeight; ++y) {
  for(uint8_t x = 0; x < mapWidth; ++x) {
    Sprites::drawOverwrite(x * tileWidth, y * tileHeight, ground,getMapTile(x, y));
    
  }
  
//draw player
arduboy.fillRect(playerX, playerY, playerWidth, playerHeight, WHITE);


}
void startJump() {
  playerVelocityY = playerJump;
  playerYi = playerY;
}

void start_Gravity() {
  playerYi = playerY;
  ballV = 0;
}
arduboy.display();
}
