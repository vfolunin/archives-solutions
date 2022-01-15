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

    map<char, int> count;
    int maxCount = 0;

    for (int i = 0; i < 5; i++) {
        string card;
        cin >> card;
        maxCount = max(maxCount, ++count[card[0]]);
    }

    cout << maxCount;
}