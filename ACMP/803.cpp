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

    int num, den, n;
    cin >> num >> den >> n;

    num %= den;
    for (int i = 0; i < n - 1; i++)
        num = num * 10 % den;

    cout << num * 10 / den;
}