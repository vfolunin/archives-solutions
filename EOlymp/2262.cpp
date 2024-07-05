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

    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            res ^= a[i] | a[j];

            for (int k = j + 1; k < a.size(); k++)
                res ^= a[i] | a[j] | a[k];
        }
    }

    cout << res;
}