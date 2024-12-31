#include "display.h"
#include "fireworks.h"

/*typedef struct pozFireworks {
    int pozY;
    int pozX;
    int isUsed;
}; 

pozFireworks listFireworks[8];
*/

int main(int argc, char *argv[])
{
    int lines, cols, prevPozX, linesBak;
    initDisplay(&lines, &cols);
    linesBak = lines;
    while (true) {
        lines = linesBak;
        prevPozX = startFirework(lines, cols); 
        delay(DELAY);
        clearScreen(linesBak, cols);
        lines--;
        while (lines > 7) {
            prevPozX = moveFirework(lines, prevPozX);
            delay(DELAY);
            clearScreen(linesBak, cols);
            lines--;
        }
        explodeFirework1(lines, prevPozX);
        delay(DELAY_BOOM);
        clearScreen(linesBak, cols);

        explodeFirework2a(lines, prevPozX);
        delay(DELAY_BOOM);
        clearScreen(linesBak, cols);

        explodeFirework3a(lines, prevPozX);
        delay(DELAY_BOOM);
    }
    exitDisplay();
    return 0;
}
