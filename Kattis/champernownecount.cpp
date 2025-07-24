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

    int size, divisor;
    cin >> size >> divisor;

    long long remainder = 0, res = 0;
    for (int i = 1; i <= size; i++) {
        string s = to_string(i);
        for (char c : s)
            remainder = (remainder * 10 + c - '0') % divisor;
        res += !remainder;
    }

    cout << res;
}