#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int queryCount;
    double x, y;
    cin >> queryCount >> x >> y;

    for (int i = 0; i < queryCount - 1; i++) {
        string direction;
        int length;
        cin >> direction >> length;

        if (direction == "N") {
            y += length;
        } else if (direction == "NE") {
            y += length / sqrt(2);
            x += length / sqrt(2);
        } else if (direction == "E") {
            x += length;
        } else if (direction == "SE") {
            y -= length / sqrt(2);
            x += length / sqrt(2);
        } else if (direction == "S") {
            y -= length;
        } else if (direction == "SW") {
            y -= length / sqrt(2);
            x -= length / sqrt(2);
        } else if (direction == "W") {
            x -= length;
        } else {
            y += length / sqrt(2);
            x -= length / sqrt(2);
        }
    }

    cout << fixed << x << " " << y;
}