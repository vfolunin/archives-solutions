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

    int queryCount;
    cin >> queryCount;

    int x = 0, y = 0;
    for (int i = 0; i < queryCount; i++) {
        string dir;
        int steps;
        cin >> dir >> steps;

        if (dir == "North")
            y += steps;
        else if (dir == "East")
            x += steps;
        else if (dir == "South")
            y -= steps;
        else
            x -= steps;
    }

    cout << x << " " << y;
}