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

    int a1, b1, a2, b2, n, a, b;
    cin >> a1 >> b1 >> a2 >> b2 >> n >> a >> b;

    cout << (a1 + a2 >= n * a && b1 + b2 >= n * b ? "Yes" : "No");
}