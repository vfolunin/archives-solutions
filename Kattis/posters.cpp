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

    int a, b, limit;
    cin >> a >> b >> limit;

    cout << max(limit - min(a, b), 0) / max(a, b);
}