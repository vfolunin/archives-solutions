#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

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
                cout << "0\n";
                return 1;
            }
            neighborDegrees.push_back(*--degrees.end() - 1);
            degrees.erase(--degrees.end());
        }

        for (int nd : neighborDegrees)
            degrees.insert(nd);
    }

    cout << "1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}