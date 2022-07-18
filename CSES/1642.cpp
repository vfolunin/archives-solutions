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
    long long targetSum;
    cin >> size >> targetSum;

    vector<long long> a(size);
    for (long long &x : a)
        cin >> x;

    map<long long, vector<pair<int, int>>> pairs;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            pairs[a[i] + a[j]].push_back({ i, j });

    for (auto &[sum, a] : pairs) {
        if (sum * 2 > targetSum)
            break;

        if (!pairs.count(targetSum - sum))
            continue;

        vector<pair<int, int>> &b = pairs[targetSum - sum];
        for (auto &[a1, a2] : a) {
            for (auto &[b1, b2] : b) {
                if (a1 != b1 && a1 != b2 && a2 != b1 && a2 != b2) {
                    cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}