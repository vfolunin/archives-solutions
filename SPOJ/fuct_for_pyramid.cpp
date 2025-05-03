#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int spaces = (size - 1) * 2, stars = 1; spaces >= 0; spaces -= 2, stars += 2) {
        cout << string(spaces, ' ');
        for (int i = 0; i < stars; i++)
            cout << "*" << (i + 1 < stars ? " " : "\n");
    }
}