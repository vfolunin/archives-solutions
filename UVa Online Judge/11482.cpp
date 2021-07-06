#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size, levelCount;
    cin >> size >> levelCount;

    if (!size)
        return 0;

    cout << "Triangular Museum " << test << "\n";

    for (int i = 0; i < levelCount * size; i++) {
        int l = levelCount * size - i - 1;
        int r = levelCount * size + i;

        for (int j = 0; j <= r; j++) {
            if (l <= j && (j - l) % (size * 2) == 0)
                cout << "/";
            else if (l <= j && (r - j) % (size * 2) == 0)
                cout << "\\";
            else if (l <= j && i % size == size - 1)
                cout << "_";
            else
                cout << " ";
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