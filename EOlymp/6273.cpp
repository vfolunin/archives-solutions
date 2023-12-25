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

    int a, b, c;
    cin >> a >> b >> c;

    int res = 0;
    while ((res + 1) * (res + 1) <= a * a + b * b + c * c)
        res++;

    cout << res;
}