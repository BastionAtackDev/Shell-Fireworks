char fireworks[] = "\\|/";

int startFirework(int lines, int cols){
    int pozY, pozX;
    pozY = lines;
    pozX = rand() % cols;
    mvprintw(pozY - 1, pozX, "%c", fireworks[1]);
    refresh();
    return pozX;
}

int moveFirework(int pozY, int pozX){
    int nextPozX = rand() % 3;
    pozX = pozX + nextPozX - 1;
    while (pozX < 0) {
        pozX++;
    }
    mvprintw(pozY - 1, pozX, "%c", fireworks[nextPozX]);
    refresh();
    return pozX;
}

void explodeFirework1(int pozY, int pozX){
    mvprintw(pozY, pozX, "0");
    refresh();
}
void explodeFirework2a(int pozY, int pozX){
    mvprintw(pozY - 1, pozX - 1, "\\");
    mvprintw(pozY - 1, pozX, "|");
    mvprintw(pozY - 1, pozX + 1, "/");

    mvprintw(pozY, pozX - 2, "--");
    mvprintw(pozY, pozX + 1, "--");

    mvprintw(pozY + 1, pozX - 1, "/");
    mvprintw(pozY + 1, pozX, "|");
    mvprintw(pozY + 1, pozX + 1, "\\");
    refresh();
}
void explodeFirework3a(int pozY, int pozX){
    mvprintw(pozY - 2, pozX - 2, "\\");
    mvprintw(pozY - 2, pozX, "|");
    mvprintw(pozY - 2, pozX + 2, "/");

    mvprintw(pozY, pozX - 3, "--");
    mvprintw(pozY, pozX + 2, "--");

    mvprintw(pozY + 2, pozX - 2, "/");
    mvprintw(pozY + 2, pozX, "|");
    mvprintw(pozY + 2, pozX + 2, "\\");
    refresh();
}
