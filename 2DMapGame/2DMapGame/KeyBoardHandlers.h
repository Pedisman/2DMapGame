#ifndef KEYBOARD_HANDLERS_h
#define KEYBOARD_HANDLERS_h

void normalKeyHandler(unsigned char key, int x, int y);
void keyPressHandler(int key, int x, int y);
void keyReleaseHandler(int key, int x, int y);

int numKeysPressed();

#endif // KEYBOARD_HANDLERS_h