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

    long long vertexCount;
    int branchFactor, queryCount;
    cin >> vertexCount >> branchFactor >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long a, b;
        cin >> a >> b;

        if (branchFactor == 1) {
            cout << abs(a - b) << "\n";
        } else {
            vector<long long> aPath;
            for (a--; a; a = (a - 1) / branchFactor)
                aPath.push_back(a);

            vector<long long> bPath;
            for (b--; b; b = (b - 1) / branchFactor)
                bPath.push_back(b);

            while (!aPath.empty() && !bPath.empty() && aPath.back() == bPath.back()) {
                aPath.pop_back();
                bPath.pop_back();
            }

            cout << aPath.size() + bPath.size() << "\n";
        }
    }
}