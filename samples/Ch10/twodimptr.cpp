#include <iostream>
using namespace std;

int main()
{
    int **p = new int *[3]; // Allocate an array of 3 pointers to integers
    for (int i = 0; i < 3; i++)
    {
        p[i] = new int[4]; // For each pointer, allocate an array of 4 integers
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
        {
            p[i][j] = i * 4 + j + 1; // Initialize the elements with some values
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << p[i][j] << " "; // Print the elements of the 2D array
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        delete [] p[i];
    }
    delete [] p; // Deallocate the array of pointers
    return 0;
}
