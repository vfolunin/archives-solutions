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

    int momentCount;
    double acceleration, length;
    cin >> momentCount >> acceleration >> length;
    acceleration /= 100;

    double initialLength = 0, prevMoment = 0, speed = 1;
    for (int i = 0; i < momentCount; i++) {
        double moment;
        cin >> moment;
        initialLength += (moment - prevMoment) * speed;
        prevMoment = moment;
        speed += acceleration;
    }
    initialLength += (length - prevMoment) * speed;

    cout << fixed << initialLength;
}
