#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int l, r;
    if (!(cin >> l >> r))
        return 0;
    if (l > r)
        swap(l, r);

    vector<int> count(10);
    for (int i = l; i <= r; i++)
        for (int value = i; value; value /= 10)
            count[value % 10]++;

    cout << "Case " << test << ": ";
    for (int i = 0; i < count.size(); i++)
        cout << i << ":" << count[i] << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}