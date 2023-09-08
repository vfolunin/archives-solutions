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

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    vector<int> pos;
    for (int i = 1; i + 1 < a.size(); i++)
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            pos.push_back(i);

    int res = 1e9;
    for (int i = 1; i < pos.size(); i++)
        res = min(res, pos[i] - pos[i - 1]);

    cout << (res != 1e9 ? res : 0);
}