#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount;
    cin >> vertexCount;

    multiset<int> degrees;
    for (int i = 0; i < vertexCount; i++) {
        int d;
        cin >> d;
        degrees.insert(d);
    }

    while (!degrees.empty()) {
        int greatestDegree = *--degrees.end();
        degrees.erase(--degrees.end());

        vector<int> neighborDegrees;
        for (int i = 0; i < greatestDegree; i++) {
            if (degrees.empty() || !*--degrees.end()) {
                cout << "No\n";
                return;
            }
            neighborDegrees.push_back(*--degrees.end() - 1);
            degrees.erase(--degrees.end());
        }

        for (int nd : neighborDegrees)
            degrees.insert(nd);
    }

    cout << "Yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}