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

    vector<int> a(size - 1);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int i = 1; i <= a[0]; i++) {
        if (a.size() * i > a.back() - i) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}