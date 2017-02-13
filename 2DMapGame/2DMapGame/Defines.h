#ifndef DEFINES_h
#define DEFINES_h

// Display window dimension size declarations
extern const int windowWidth;
extern const int windowHeight;

// Map dimensions
static const int xDim = 20;
static const int yDim = 20;

extern int map[yDim][xDim];

// Block types
enum { WALL_BLOCK = 1 };

// Key enums
enum {ESCAPE_KEY = 27, LEFT_KEY = 100, UP_KEY = 101, RIGHT_KEY = 102, DOWN_KEY = 103};
enum {LEFT = 0, UP, RIGHT, DOWN};

// Player movement register
extern bool pressedKeys[4];

// Declare Block Colors
extern const int wallBlockColor[3];
extern const int playerBlockColor[3];

// Callback timer period
extern const int playerPeriod;

#endif // DEFINES_h
