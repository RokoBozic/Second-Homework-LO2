#include "game_of_life.h"
#include <cstdlib>
#include <ctime>

game_of_life::game_of_life() {
    srand(time(nullptr));
    for (unsigned int i = 0; i < ROWS; ++i) {
        for (unsigned int j = 0; j < COLS; ++j) {
            _generation[i][j] = random_value();
        }
    }
}

bool game_of_life::random_value() {
    return rand() % 4 == 0;
}

void game_of_life::next_generation() {
    for (unsigned int i = 0; i < ROWS; ++i) {
        for (unsigned int j = 0; j < COLS; ++j) {
            int neighbors = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && _generation[ni][nj]) {
                        ++neighbors;
                    }
                }
            }
            if (_generation[i][j]) {
                _next_generation[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else {
                _next_generation[i][j] = (neighbors == 3);
            }
        }
    }

    for (unsigned int i = 0; i < ROWS; ++i) {
        for (unsigned int j = 0; j < COLS; ++j) {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw() {
    system("cls");
    for (unsigned int i = 0; i < ROWS; ++i) {
        for (unsigned int j = 0; j < COLS; ++j) {
            cout << (_generation[i][j] ? '*' : '-') << ' ';
        }
        cout << endl;
    }
}