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
 
    int x = 0, y = 0, steps;
    string direction;

    while (cin >> direction >> steps) {
        if (direction == "North")
            y += steps;
        else if (direction == "South")
            y -= steps;
        else if (direction == "East")
            x += steps;
        else
            x -= steps;
    }

    cout << x << " " << y;
}