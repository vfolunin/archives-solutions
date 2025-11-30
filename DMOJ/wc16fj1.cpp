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

    vector<vector<int>> a(size, vector<int>(size));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            cin >> a[i][j];

    vector<int> wins(a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            wins[i] += a[i][j] > a[j][i];
            wins[j] += a[i][j] < a[j][i];
        }
    }

    cout << max_element(wins.begin(), wins.end()) - wins.begin() + 1;
}