#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool better(int a, int b) {
    int aSum = digitSum(a);
    int bSum = digitSum(b);
    return aSum < bSum || aSum == bSum && a > b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 1;
    for (int d = 2; d <= n; d++)
        if (n % d == 0 && better(res, d))
            res = d;
    
    cout << res;
}