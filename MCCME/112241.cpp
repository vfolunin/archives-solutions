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

    int size;
    cin >> size;

    vector<int> a(size);
    int xorSum = 0;

    for (int &value : a) {
        cin >> value;
        xorSum ^= value;
    }

    cout << (xorSum ? 1 : 2);
}