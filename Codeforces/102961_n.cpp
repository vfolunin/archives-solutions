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

    int blockCount;
    cin >> blockCount;

    multiset<int> towers;
    for (int i = 0; i < blockCount; i++) {
        int blockSize;
        cin >> blockSize;

        auto it = towers.upper_bound(blockSize);
        if (it != towers.end())
            towers.erase(it);
        towers.insert(blockSize);
    }

    cout << towers.size();
}