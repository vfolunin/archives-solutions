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

    sort(a.begin(), a.end());

    for (int i = 0; i + 2 < a.size(); i++) {
        if (a[i] + a[i + 1] != a[i + 2]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}