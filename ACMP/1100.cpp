#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(unsigned long long n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    unsigned long long a = 0;
    while (a * 10 + 9 <= n)
        a = a * 10 + 9;

    unsigned long long b = n - a;

    cout << digitSum(a) + digitSum(b) << "\n" << a << " " << b;
}