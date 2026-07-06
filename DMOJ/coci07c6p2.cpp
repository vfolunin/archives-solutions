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

    int lightCount, length;
    cin >> lightCount >> length;

    int time = 0, x = 0;
    for (int i = 0; i < lightCount; i++) {
        int lightX, red, green;
        cin >> lightX >> red >> green;

        time += lightX - x;
        if (time % (red + green) < red)
            time += red - time % (red + green);
        x = lightX;
    }
    time += length - x;

    cout << time;
}