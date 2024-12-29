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

    long long limit;
    cin >> limit;

    int res = 0;
    for (int half = 10; 1; half *= 10) {
        for (long long value = half / 10; value < half; value++) {
            if (value * half + value > limit) {
                cout << res;
                return 0;
            }
            res++;
        }
    }
}