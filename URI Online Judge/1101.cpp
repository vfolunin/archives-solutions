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

    while (1) {
        int l, r;
        cin >> l >> r;

        if (l <= 0 || r <= 0)
            break;

        if (l > r)
            swap(l, r);

        int sum = 0;
        for (int i = l; i <= r; i++) {
            cout << i << " ";
            sum += i;
        }
        cout << "Sum=" << sum << "\n";
    }
}