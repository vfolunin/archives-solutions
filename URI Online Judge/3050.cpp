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

    int houseCount, maxPrev;
    cin >> houseCount >> maxPrev;

    int maxDist = 0;
    for (int i = 1; i < houseCount; i++) {
        int cur;
        cin >> cur;
        maxDist = max(maxDist, cur + i + maxPrev);
        maxPrev = max(maxPrev, cur - i);
    }
    
    cout << maxDist << "\n";
}