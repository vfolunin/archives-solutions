#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int squareSize, thickness, squareCount;
    cin >> squareSize >> thickness >> squareCount;

    if (!squareSize)
        return 0;

    int size = (thickness + squareSize) * squareCount + thickness;
    
    cout << "Case " << test << ":\n";
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y % (thickness + squareSize) < thickness ||
                x % (thickness + squareSize) < thickness)
                cout << "*";
            else
                cout << ".";
        }
        cout << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}