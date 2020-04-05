#include <iostream> // cout, endl
#include <conio.h> // getch, kbhit
#include <windows.h> // Sleep

using namespace std;

bool gameOver; // global variables
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup() { // set default values
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#"; // top wall
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#"; // left wall
            if (i == y && j == x) // snake head
                cout << "O";
            else if (i == fruitY && j == fruitX) // fruit
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // snake tail
                        print = true;
                    }
                }
                if (!print)
                    cout << " "; //  field
            }

            if (j == width - 1)
                cout << "#"; // right wall
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) 
        cout << "#"; // bottom wall
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input() {
    if (_kbhit()) { // if button pressed
        switch (_getch()) { // get this button value
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
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y; // variables to change tail
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) { // change tail
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) { // change position
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

    if (x >= width) // go through walls
        x = 0;
    else if(x < 0)
        x = width - 1;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < nTail; i++) // if touch tail
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) { // if get fruit
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main() {
    Setup();
    while (!gameOver) { // main loop
        Draw();
        Input();
        Logic();
        Sleep(20); // to be not too fast
    }
    return 0;
}
