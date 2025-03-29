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

    vector<int> a = { 1, 1 };
    for (int i = 2; i <= r; i++)
        a.push_back((a[i - 2] + a[i - 1]) % 3);
    
    cout << count(a.begin() + l, a.begin() + r + 1, 0);
}