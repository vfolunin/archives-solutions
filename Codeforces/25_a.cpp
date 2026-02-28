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

    vector<vector<int>> pos(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value % 2].push_back(i);
    }

    cout << pos[pos[1].size() == 1][0] + 1;
}