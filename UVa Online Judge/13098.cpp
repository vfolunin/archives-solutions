#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

pair<vector<int>, vector<int>> prepare() {
    vector<int> t1, t2;
    int t = 0;
    for (int i = 1; t <= 1e7; i++) {
        t += i;
        t1.push_back(t);
    }

    for (int i = 0; i < t1.size(); i++)
        for (int j = i; j < t1.size(); j++)
            t2.push_back(t1[i] + t1[j]);

    sort(t2.begin(), t2.end());
    t2.erase(unique(t2.begin(), t2.end()), t2.end());

    return { t1, t2 };
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static auto [t1, t2] = prepare();

    if (binary_search(t1.begin(), t1.end(), n))
        cout << "1\n";
    else if (binary_search(t2.begin(), t2.end(), n))
        cout << "2\n";
    else
        cout << "3\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}