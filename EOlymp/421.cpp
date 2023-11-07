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

    double n, d;
    cin >> n >> d;

    int res = 0;
    while (n > d) {
        n /= d;
        res++;
    }

    cout << res;
}