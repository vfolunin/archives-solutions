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
    for (int &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        int digit = a[i];
        if (i)
            digit += a[i - 1];
        if (i + 1 < n)
            digit += a[i + 1];

        cout << digit << "\n";
    }
}