#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    cin.ignore();
    vector<int> v;
    while (cin.peek() != '\n') {
        v.emplace_back();
        cin >> v.back();
    }
    return v;
}

void solve() {
    vector<int> weights = readInts();

    int totalWeight = 0;
    for (int weight : weights)
        totalWeight += weight;

    if (totalWeight % 2) {
        cout << "NO\n";
        return;
    }

    totalWeight /= 2;

    vector<int> can(totalWeight + 1);
    can[0] = 1;

    for (int weight : weights)
        for (int i = totalWeight; i >= weight; i--)
            if (can[i - weight])
                can[i] = 1;

    cout << (can[totalWeight] ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}