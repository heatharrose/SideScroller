#include <Arduboy2.h>
const unsigned char ground[] PROGMEM = {

  8, 8,

  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xf3, 0x9c, 0xff, 0xb5, 0xff, 0x29, 0xff, 0x5a,
};

const unsigned char mapArray[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

constexpr uint8_t tileWidth = 8;
constexpr uint8_t tileHeight = 8;
constexpr uint8_t mapWidth = 17;
constexpr uint8_t mapHeight = 8;

uint8_t getMapTile(uint8_t x, uint8_t y) {
  return pgm_read_byte(&mapArray[x + (mapWidth * y)]);
}

constexpr size_t screenWidth = (WIDTH / tileWidth);
