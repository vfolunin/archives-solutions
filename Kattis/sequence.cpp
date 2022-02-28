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

    vector<int> res = { 1 };
    while (res.back() * 2 <= n)
        res.push_back(res.back() * 2);

    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
}