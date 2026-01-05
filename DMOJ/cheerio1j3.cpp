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

    vector<int> count(size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            char c;
            cin >> c;

            count[x] += c == 'S';
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (y + count[x] >= size ? 'S' : '.');
        cout << "\n";
    }
}