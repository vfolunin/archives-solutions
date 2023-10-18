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

    if (size % 4 == 0) {
        for (int i = 0; i < size / 4; i++)
            cout << "+--+";
    } else if (size % 4 == 3) {
        cout << "++-";
        for (int i = 0; i < size / 4; i++)
            cout << "+--+";
    } else {
        cout << "IMPOSSIBLE";
    }
}