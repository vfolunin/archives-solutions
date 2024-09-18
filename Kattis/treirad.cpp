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
    for (long long i = 1; i * (i + 1) * (i + 2) < limit; i++)
        res++;

    cout << res;
}