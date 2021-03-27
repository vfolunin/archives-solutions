#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long den, num;
    cin >> den >> num;

    if (!den && !num)
        return 0;

    long long num2 = num - 1, den2 = den - 1;
    num = min(num, den);
    num2 = min(num2, den2);

    cout << "Case " << test << ": ";
    if (den2 == 0)
        cout << ":-\\\n";
    else if (num * den2 == num2 * den)
        cout << ":-|\n";
    else if (num * den2 < num2 * den)
        cout << ":-)\n";
    else
        cout << ":-(\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}