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

    vector<vector<int>> a(size, vector<int>(3));
    for (int j = 0; j < a[0].size(); j++)
        for (int i = 0; i < a.size(); i++)
            cin >> a[i][j];

    for (vector<int> &a : a) {
        sort(a.begin(), a.end());
        cout << a[1] << " ";
    }
}