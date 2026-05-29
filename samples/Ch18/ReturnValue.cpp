#include <iostream>
#include <fstream>
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

int getHighScore()
{
    ifstream f;
    int high = -1;
    f.open("scores.txt");
    if (f.fail()) {
        cerr << "File could not be opened.\n";
        return -1;
    }
    int num;
    f >> high;
    while (f >> num) {
        if (num > high) {
            high = num;
        }
    }
    f.close();
    return high;
}

int main()
{
    int highscore = getHighScore();
    cout << "The high score is: " << highscore << endl;
    return 0;
}
