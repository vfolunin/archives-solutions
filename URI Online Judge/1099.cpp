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

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        if (l > r)
            swap(l, r);

        int sum = 0;
        for (int j = l + 1; j < r; j++)
            if (j % 2)
                sum += j;
        cout << sum << "\n";
    }
}