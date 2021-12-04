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

    int m, a, b;
    cin >> m >> a >> b;

    cout << max(max(a, b), m - a - b) << "\n";
}