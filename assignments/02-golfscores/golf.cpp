#include <iostream>

using namespace std;

const int NUM_PLAYERS = 4;
const int NUM_HOLES = 18;

void calcScore(int par[], int delta[][NUM_HOLES], int score[]);
void calcAvg(int part[], int delta[][NUM_HOLES], double avg[]);

int main() {
    int par[NUM_HOLES];
    int delta[NUM_PLAYERS][NUM_HOLES];
    int score[NUM_PLAYERS];
    double avg[NUM_HOLES];
    for (int i = 0; i < 18; i++) {
        cin >> par[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            cin >> delta[i][j];
        }
    }
    calcScore(par, delta, score);
    calcAvg(par, delta, avg);

    cout << fixed;
    cout.precision(1);
    for (int i = 0; i < 4; i++) {
        cout << "Player " << i + 1 << ": " << score[i] << endl;
    }
    for (int j = 0; j < 18; j++) {
        cout << "Hole " << j + 1 << ": " << avg[j] << endl;
    }
    return 0;
}

void calcScore(int par[], int delta[][NUM_HOLES], int score[]) {
    for (int i = 0; i < 4; i++) {
        score[i] = 0;
        for (int j = 0; j < 18; j++) {
            score[i] += par[j] + delta[i][j];
        }
    }
}

void calcAvg(int par[], int delta[][NUM_HOLES], double avg[]) {
    for (int j = 0; j < 18; j++) {
        avg[j] = 0;
        for (int i = 0; i < 4; i++) {
            avg[j] += par[j] + delta[i][j];
        }
        avg[j] /= 4;
    }
}
