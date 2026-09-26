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

    vector<int> used(size + 1, 1);
    used[0] = 0;

    for (int i = size; i; i--)
        if (i * 2 < used.size() && used[i * 2] || i * 4 < used.size() && used[i * 4])
            used[i] = 0;

    cout << count(used.begin(), used.end(), 1);
}