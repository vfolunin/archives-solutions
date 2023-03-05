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

    vector<vector<int>> a(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        a[i % 2].push_back(value);
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].rbegin(), a[1].rend());

    for (int i = 0; i < a[1].size(); i++)
        cout << a[0][i] << " " << a[1][i] << " ";
    if (size % 2)
        cout << a[0].back();
}