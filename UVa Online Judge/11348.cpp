#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int friendCount;
    cin >> friendCount;

    map<int, set<int>> owners;
    for (int i = 0; i < friendCount; i++) {
        int stampCount;
        cin >> stampCount;

        for (int j = 0; j < stampCount; j++) {
            int stamp;
            cin >> stamp;
            owners[stamp].insert(i);
        }
    }

    vector<int> uniqueStampCount(friendCount);
    double totalUniqueStampCount = 0;
    for (auto &[_, owners] : owners) {
        if (owners.size() == 1) {
            uniqueStampCount[*owners.begin()]++;
            totalUniqueStampCount++;
        }
    }

    if (!totalUniqueStampCount) {
        fill(uniqueStampCount.begin(), uniqueStampCount.end(), 1);
        totalUniqueStampCount = friendCount;
    }

    cout << "Case " << test << ":" << fixed;
    cout.precision(6);
    for (int count : uniqueStampCount)
        cout << " " << count / totalUniqueStampCount * 100 << "%";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}