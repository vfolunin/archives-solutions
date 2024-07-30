#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int bitCount(int n) {
    int res = 1;
    while (n > 1) {
        res++;
        n /= 2;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num, den;
    cin >> num >> den;

    for (int i = num; bitCount(i) == bitCount(num); i++) {
        if ((i & num) == num && i % den == 0) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}