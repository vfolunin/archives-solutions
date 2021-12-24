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

    int strikeCount;
    cin >> strikeCount;
    
    set<pair<int, int>> strikes;

    for (int i = 0; i < strikeCount; i++) {
        int x, y;
        cin >> x >> y;

        if (strikes.count({ x, y })) {
            cout << "1\n";
            return 0;
        }

        strikes.insert({ x, y });
    }

    cout << "0\n";
}