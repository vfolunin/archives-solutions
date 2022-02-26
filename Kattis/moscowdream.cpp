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

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a && b && c && n >= 3 && a + b + c >= n)
        cout << "YES";
    else
        cout << "NO";
}