#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long arrangementCount(int n, int k) {
    long long res = 1;
    for (int i = 0; i < k; i++)
        res *= n - i;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int &value : a)
        cin >> value;

    long long res = 1;
    for (int i = 0; i < a.size(); i++) {
        res += (a[i] - 1) * arrangementCount(n - 1 - i, k - 1 - i);
        for (int j = i + 1; j < a.size(); j++)
            a[j] -= a[i] < a[j];
    }

    cout << res;
}