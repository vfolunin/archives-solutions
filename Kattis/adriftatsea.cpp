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

    string sa, sb;
    cin >> sa >> sb;

    map<string, int> angle = {
        { "E", 0 }, { "NE", 45 }, { "N", 90 }, { "NW", 135 },
        { "W", 180 }, { "SW", 225 }, { "S", 270 }, { "SE", 315 }
    };

    int a = angle[sa], b = angle[sb];
    int s = (a - b + 360) % 360;
    int p = (b - a + 360) % 360;

    if (s == 0 || p == 0)
        cout << "Keep going straight";
    else if (s == 180)
        cout << "U-turn";
    else if (s < p)
        cout << "Turn " << s << " degrees starboard";
    else
        cout << "Turn " << p << " degrees port";
}