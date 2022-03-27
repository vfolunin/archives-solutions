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

    double volume, leak, dist;
    cin >> volume >> leak >> dist;
    volume /= 2;

    int maxSpeed = -1;
    for (int i = 0; i < 7; i++) {
        int speed;
        double efficiency;
        cin >> speed >> efficiency;

        double time = dist / speed;
        if (dist / efficiency + time * leak <= volume)
            maxSpeed = speed;
    }

    if (maxSpeed != -1)
        cout << "YES " << maxSpeed;
    else
        cout << "NO";
}