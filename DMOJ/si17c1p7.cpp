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
    double pos, speed;
    cin >> size >> pos >> speed;

    double time = 0;
    for (int i = 1; i < size; i++) {
        double curPos, curSpeed;
        cin >> curPos >> curSpeed;

        if (speed < curSpeed) {
            time += (pos - curPos) / speed;
            pos = curPos;
            speed = curSpeed;
        }
    }
    time += pos / speed;

    cout << fixed << time;
}