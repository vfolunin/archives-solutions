#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> pos;
    int value;

    for (int i = 0; cin >> value; i++) {
        if (pos.count(-value)) {
            cout << pos[-value] << " " << i;
            return 0;
        }
        pos[value] = i;
    }
}