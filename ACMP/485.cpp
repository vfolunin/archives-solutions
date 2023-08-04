#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int isGood(int n, int divisor, int remainder) {
    for (int i = 0; i < divisor; i++) {
        if (n < divisor || n % divisor != remainder)
            return 0;
        n -= n / divisor + remainder;
    }
    return 1;
}

void main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int divisor, remainder;
    cin >> divisor >> remainder;

    int res = 1;
    while (!isGood(res, divisor, remainder))
        res++;

    cout << res;
}