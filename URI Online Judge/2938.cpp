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

    int birdWeight, foodWeight, leafCount;
    cin >> birdWeight >> foodWeight >> leafCount;

    int res = 0;
    for (int i = 0; i < leafCount; i++) {
        int limit;
        cin >> limit;

        if (birdWeight + foodWeight > limit) {
            if (birdWeight > limit)
                break;
            res += i > 0 && foodWeight > 0;
            foodWeight -= birdWeight + foodWeight - limit;
        }
    }

    cout << res << "\n";
}