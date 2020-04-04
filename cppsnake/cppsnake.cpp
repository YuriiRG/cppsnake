#include <iostream>

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
    x = WIDTH / 2;
    y = HEIGHT / 2;
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
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= WIDTH; i++) {
        cout << "#";
    }
    cout << endl;
}

void input() {

}

void logic() {

}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
    return 0;
}