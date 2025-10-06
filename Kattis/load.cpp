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

    int size;
    cin >> size;

    vector<int> a(size), b(size);
    for (int i = 0; i < a.size(); i++) {
        int factor;
        cin >> a[i] >> factor >> b[i];
        a[i] *= factor;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];

    cout << res;
}