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
enum {ESCAPE = 27, LEFT = 100, UP = 101, RIGHT = 102, DOWN = 103};

// Declare Block Colors
extern const int wallBlockColor[3];

#endif // DEFINES_h
