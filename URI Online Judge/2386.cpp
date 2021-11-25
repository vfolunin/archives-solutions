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

    int aperture, starCount;
    cin >> aperture >> starCount;

    int seenStarCount = 0;
    for (int i = 0; i < starCount; i++) {
        int flux;
        cin >> flux;
        seenStarCount += flux * aperture >= 4e7;
    }

    cout << seenStarCount << "\n";
}