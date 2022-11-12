#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    vector<int> count(10);
    while (n) {
        count[n % 10]++;
        n /= 10;
    }
    return *max_element(count.begin(), count.end()) == 3;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);

    int res = 0;
    for (int i = l; i <= r; i++)
        if (isGood(i))
            cout << i << "\n";
}