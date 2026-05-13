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

    int n, k, p;
    cin >> n >> k >> p;

    cout << max((n * p + 99) / 100 - k, 0);
}