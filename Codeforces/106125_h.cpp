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

    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    vector<int> index(a.size());
    while (1) {
        bool found = 0;

        for (int i = 0; i < a.size() && !found; i++) {
            if (index[i] == a[i].size())
                continue;

            for (int j = i + 1; j < a.size() && !found; j++) {
                if (index[j] == a[j].size() || a[i][index[i]] != a[j][index[j]])
                    continue;

                cout << a[i][index[i]];
                index[i]++;
                index[j]++;
                found = 1;
            }
        }

        if (!found)
            break;
    }
}