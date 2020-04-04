#include <iostream>
#include <conio.h>
#include <windows.h> // Sleep()

using namespace std;

bool gameOver;
const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup() {
    gameOver = false;
    dir = STOP;
    x = WIDTH / 2 - 1;
    y = HEIGHT / 2 - 1;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i <= WIDTH; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((j == 0) || (j == (WIDTH - 1))) {
                cout << "#";
            }
            if ((i == y) && (j == x)) {
                cout << "0";
            }
            else if ((i == fruitY) && (j == fruitX)) {
                cout << "F"; // press F to pay respects
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i <= WIDTH; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void logic() {
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    if ((x > WIDTH) || (x < 0) || (y > HEIGHT) || (y < 0)) {
        gameOver = true;
    }
    if ((x == fruitX) && (y == fruitY)) {
        score++;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(20); // To be not too fast
    }
    return 0;
}