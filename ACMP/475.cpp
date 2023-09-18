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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    sort(a.begin(), a.end());

    for (int i = 2; i < a.size(); i++) {
        if (a[i] - a[i - 1] != a[1] - a[0]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}