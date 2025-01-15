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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, queryCount;
    cin >> size >> queryCount;

    unordered_map<int, int> pos;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!pos.count(value))
            pos[value] = i;
    }

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        if (pos.count(value))
            cout << pos[value] << "\n";
        else
            cout << "-1\n";
    }
}