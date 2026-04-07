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

    vector<int> a(6);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    do {
        if (a[0] + a[1] + a[2] == a[3] + a[4] + a[5]) {
            cout << "YES";
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "NO";
}