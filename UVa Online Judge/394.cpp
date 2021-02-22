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

    int arrayCount, queryCount;
    cin >> arrayCount >> queryCount;

    map<string, long long> baseAddress, elemSize;
    map<string, vector<pair<long long, long long>>> dim;
    map<string, vector<long long>> c;
    for (int i = 0; i < arrayCount; i++) {
        string name;
        cin >> name >> baseAddress[name] >> elemSize[name];

        int dimCount;
        cin >> dimCount;

        dim[name].resize(dimCount);
        for (auto &[l, r] : dim[name])
            cin >> l >> r;

        c[name].resize(dimCount + 1);
        c[name].back() = elemSize[name];
        c[name].front() = baseAddress[name] - c[name].back() * dim[name].back().first;
        
        for (int j = c[name].size() - 2; j > 0; j--) {
            c[name][j] = c[name][j + 1] * (dim[name][j].second - dim[name][j].first + 1);
            c[name].front() -= c[name][j] * dim[name][j - 1].first;
        }
    }

    for (int i = 0; i < queryCount; i++) {
        string name;
        cin >> name;

        vector<int> index(dim[name].size());
        for (int &x : index)
            cin >> x;

        int res = c[name][0];
        for (int j = 0; j < index.size(); j++)
            res += c[name][j + 1] * index[j];

        cout << name << "[";
        for (int j = 0; j < index.size(); j++) {
            cout << index[j];
            cout << (j + 1 < index.size() ? ", " : "] = ");
        }
        cout << res << "\n";
    }
}