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

    if (!size) {
        cout << 1;
        return 0;
    }

    vector<vector<long long>> ways = { {}, { 1, 1, 1 } };
    for (int i = 2; i <= size; i++) {
        ways.push_back({
            ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2],
            ways[i - 1][1] + ways[i - 1][2],
            ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2]
        });
    }
    
    cout << ways[size][0] + ways[size][1] + ways[size][2];
}