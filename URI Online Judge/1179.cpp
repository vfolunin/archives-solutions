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

    vector<vector<int>> a(2);
    vector<string> name = { "par", "impar" };

    for (int i = 0; i < 15; i++) {
        int x;
        cin >> x;

        int index = x % 2 != 0;

        a[index].push_back(x);
        if (a[index].size() == 5) {
            for (int j = 0; j < 5; j++)
                cout << name[index] << "[" << j << "] = " << a[index][j] << "\n";
            a[index].clear();
        }
    }

    for (int i = 1; i >= 0; i--)
        for (int j = 0; j < a[i].size(); j++)
            cout << name[i] << "[" << j << "] = " << a[i][j] << "\n";
}