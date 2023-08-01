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

    int size, mod;
    cin >> size >> mod;

    long long factorial = 1, power = 1, sum = 0;
    for (int i = 1; i <= size; i++) {
        factorial = factorial * i % mod;
        power = power * 2 % mod;
        sum = (sum + factorial * power % mod) % mod;
    }

    cout << sum;
}