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

    int size, maxJump;
    cin >> size >> maxJump;

    const int MOD = 1e6 + 7;
    vector<int> ways(size + 1);
    ways[1] = 1;

    for (int i = 1; i <= size; i++)
        for (int jump = 1; jump <= i && jump <= maxJump; jump++)
            ways[i] = (ways[i] + ways[i - jump]) % MOD;

    cout << ways[size];
}