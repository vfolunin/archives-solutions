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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int res = 1;
    while (res * a % 100 || res * b % 100 || res * c % 100 || res * d % 100)
        res++;

    cout << res;
}