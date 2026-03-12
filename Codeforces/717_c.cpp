#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0, j = a.size() - 1; i < a.size(); i++, j--)
        res += a[i] * a[j];

    cout << res % 10007;
}