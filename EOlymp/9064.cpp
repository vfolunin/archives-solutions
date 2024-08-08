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

    long long a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    long long res = 0;
    while (a >= (res + 1) * (res + 1) / 2 && b >= ((res + 1) * (res + 1) + 1) / 2)
        res++;

    cout << res;
}