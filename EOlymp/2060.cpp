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

    unsigned long long res = 1;
    for (int i = 0; i < n; i++)
        res = (res + 1) * 2;

    cout << res;
}