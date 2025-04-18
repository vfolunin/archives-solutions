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
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i + 1 < a.size(); i++) {
        bool ok = 1;
        for (int j = 0; j < i && ok; j++)
            ok &= a[j] > a[j + 1];
        for (int j = i + 1; j + 1 < a.size() && ok; j++)
            ok &= a[j] < a[j + 1];

        if (ok) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}