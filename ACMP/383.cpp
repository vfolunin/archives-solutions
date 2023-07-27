#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    int sum = 0, count = 0;
    while (n) {
        sum += n % 10;
        count++;
        n /= 10;
    }
    return sum % count == 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++) {
        do {
            res++;
        } while (!isGood(res));
    }

    cout << res;
}