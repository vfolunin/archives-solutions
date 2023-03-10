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

    vector<int> a(size);
    vector<vector<int>> b(2);
    for (int &value : a) {
        cin >> value;
        b[value % 2 != 0].push_back(value);
    }

    sort(b[0].rbegin(), b[0].rend());
    sort(b[1].begin(), b[1].end());

    vector<int> bi(2);
    for (int value : a)
        cout << b[value % 2 != 0][bi[value % 2 != 0]++] << " ";
}