#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<double, int> &a, pair<double, int> &b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

bool solve(int test) {
    int length;
    if (!(cin >> length))
        return 0;

    vector<pair<double, int>> p(10);
    for (int i = 0; i < 10; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end(), compare);

    cout << "Caso " << test << ": ";
    for (int i = 0; i < length; i++)
        cout << p[i].second;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}