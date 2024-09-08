#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bit>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, width;
    cin >> size >> width;

    vector<int> a(size);
    for (int &value : a) {
        string s;
        cin >> s;
        value = stoi(s, 0, 2);
    }

    int res = 1e9;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            res = min(res, popcount((unsigned)a[i] ^ a[j]));

    cout << res;
}