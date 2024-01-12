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

    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << (a == b ? "YES" : "NO");
}