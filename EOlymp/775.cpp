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

    int size, n, m;
    cin >> size >> n >> m;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int product = n * m;
    sort(a.rbegin(), a.rend());

    int res = 0;
    while (product > 0) {
        product -= a[res];
        res++;
    }

    cout << res;
}