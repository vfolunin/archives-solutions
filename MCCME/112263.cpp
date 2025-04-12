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

    vector<vector<int>> ways(size + 1, vector<int>(size + 1));
    ways[0][0] = 1;

    for (int count = 1; count <= size; count++)
        for (int last = 1; last <= count; last++)
            for (int prev = 0; prev <= last; prev++)
                ways[count][last] += ways[count - last][prev];

    int res = -1;
    for (int last = 1; last <= size; last++)
        res += ways[size][last];

    cout << res;
}