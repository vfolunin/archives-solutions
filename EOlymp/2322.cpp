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

    int targetValue, size;
    cin >> targetValue >> size;

    vector<int> contains(size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;
            contains[x] |= value == targetValue;
        }
    }

    for (int c : contains)
        cout << (c ? "YES\n" : "NO\n");
}