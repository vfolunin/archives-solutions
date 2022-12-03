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

    int size, badCount;
    cin >> size >> badCount;

    vector<int> bad(size + 1);
    for (int i = 0; i < badCount; i++) {
        int value;
        cin >> value;
        bad[value] = 1;
    }

    vector<long long> ways(size + 1);
    ways[0] = 1;
    for (int i = 1; i <= size; i++) {
        if (bad[i])
            continue;
        ways[i] = ways[i - 1];
        if (i >= 2)
            ways[i] += ways[i - 2];
    }

    cout << ways.back();
}