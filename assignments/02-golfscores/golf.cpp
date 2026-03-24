#include <iostream>

using namespace std;

const int NUM_PLAYERS = 4;
const int NUM_HOLES = 18;

void calcScore(const int par[], const int delta[][NUM_HOLES], int score[]);
void calcAvg(const int par[], const int delta[][NUM_HOLES], double avg[]);

int main() {
    int par[NUM_HOLES];
    int delta[NUM_PLAYERS][NUM_HOLES];
    int score[NUM_PLAYERS];
    double avg[NUM_HOLES];
    for (int i = 0; i < NUM_HOLES; i++) {
        cin >> par[i];
    }
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_HOLES; j++) {
            cin >> delta[i][j];
        }
    }
    calcScore(par, delta, score);
    calcAvg(par, delta, avg);

    cout << fixed;
    cout.precision(1);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        cout << "Player " << i + 1 << ": " << score[i] << endl;
    }
    for (int j = 0; j < NUM_HOLES; j++) {
        cout << "Hole " << j + 1 << ": " << avg[j] << endl;
    }
    return 0;
}

void calcScore(const int par[], const int delta[][NUM_HOLES], int score[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        score[i] = 0;
        for (int j = 0; j < NUM_HOLES; j++) {
            score[i] += par[j] + delta[i][j];
        }
    }
}

void calcAvg(const int par[], const int delta[][NUM_HOLES], double avg[]) {
    for (int j = 0; j < NUM_HOLES; j++) {
        avg[j] = 0;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            avg[j] += par[j] + delta[i][j];
        }
        avg[j] /= NUM_PLAYERS;
    }
}
