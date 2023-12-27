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

    long long total = 9, sub = 8;
    for (int i = 1; i < n; i++) {
        total *= 10;
        sub *= 9;
    }

    cout << total - sub;
}