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

    int limit;
    cin >> limit;

    int res = 0;
    while ((res + 1) * (res + 2) / 2 <= limit)
        res++;

    cout << res;
}