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

    int value, divisor;
    cin >> value >> divisor;

    int res = 0;
    while (value) {
        if (value % divisor == 0) {
            res++;
            value /= divisor;
        } else {
            res += value % divisor;
            value -= value % divisor;
        }
    }

    cout << res;
}