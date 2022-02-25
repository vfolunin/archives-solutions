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

    int guestCount;
    cin >> guestCount;

    map<int, int> prevPos;
    int maxDist = guestCount;

    for (int i = 0; i < guestCount; i++) {
        int language;
        cin >> language;

        if (prevPos.count(language))
            maxDist = min(maxDist, i - prevPos[language]);

        prevPos[language] = i;
    }

    cout << maxDist;
}