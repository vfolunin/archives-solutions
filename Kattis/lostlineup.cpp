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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int x = 1; x < n; x++) {
        int index;
        cin >> index;
        a[index + 1] = x;
    }

    for (int x : a)
        cout << x + 1 << " ";
}