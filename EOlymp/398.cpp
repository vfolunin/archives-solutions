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
    n++;

    long long res = 0;
    while (res * (res + 1) / 2 + 1 < n)
        res++;

    cout << res;
}