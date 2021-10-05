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

    int l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);

    int sum = 0;
    for (int i = l; i <= r; i++)
        if (i % 13)
            sum += i;
    cout << sum << "\n";
}