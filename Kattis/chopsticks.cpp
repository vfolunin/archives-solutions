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

    int needCount, pairCount;
    cin >> needCount >> pairCount;

    map<pair<int, int>, int> count;
    for (int i = 0; i < pairCount; i++) {
        int a, b;
        cin >> a >> b;

        count[{ a, b }]++;
    }

    for (auto &[_, count] : count)
        needCount -= count / 2;

    cout << (needCount <= 0 ? "yes" : "no");
}