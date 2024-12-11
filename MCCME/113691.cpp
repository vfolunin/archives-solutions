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

    int size, aSize, bSize;
    cin >> size >> aSize >> bSize;

    vector<int> used(size);

    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        used[value - 1] = 1;
    }
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        used[value - 1] = 1;
    }

    cout << count(used.begin(), used.end(), 0) << "\n";
    for (int i = 0; i < used.size(); i++)
        if (!used[i])
            cout << i + 1 << " ";
}