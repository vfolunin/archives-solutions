#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, n;
    cin >> a >> b >> n;

    unordered_set<int> values;
    for (int ka = 0, kb = n; ka <= n; ka++, kb--)
        values.insert(ka * a + kb * b);

    cout << values.size();
}