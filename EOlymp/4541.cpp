#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getDigitCount(int n) {
    vector<int> digitCount(10);
    for (; n; n /= 10)
        digitCount[n % 10]++;
    return digitCount;
}

int getNewDigitCount(int n) {
    vector<int> a = getDigitCount(n);
    vector<int> b = getDigitCount(n + 1);

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += max(b[i] - a[i], 0);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, price;
    cin >> n >> price;

    cout << 1LL * getNewDigitCount(n) * price;
}