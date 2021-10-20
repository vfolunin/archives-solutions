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

    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;

    if (l1 <= n && n <= r1 && l2 <= n && n <= r2)
        cout << "possivel\n";
    else
        cout << "impossivel\n";
}