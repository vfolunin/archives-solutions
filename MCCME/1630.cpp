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

    int teamCount, teamSize;
    cin >> teamCount >> teamSize;

    vector<int> a(teamCount * teamSize);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < a.size(); i += teamSize)
        res = max(res, a[i + teamSize - 1] - a[i]);

    cout << res;
}