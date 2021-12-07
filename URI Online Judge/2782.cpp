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

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ladderCount = 1;
    for (int i = 2; i < n; i++)
        ladderCount += a[i - 1] - a[i - 2] != a[i] - a[i - 1];

    cout << ladderCount << "\n";
}