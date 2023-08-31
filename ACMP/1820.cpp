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

    int circleCount, jumpWidth;
    cin >> circleCount >> jumpWidth;

    for (int i = 0; i < circleCount; i++) {
        int circleWidth;
        cin >> circleWidth;

        if (jumpWidth < circleWidth) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}