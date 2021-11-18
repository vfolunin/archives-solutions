#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;

    int num = num1 * den2 + num2 * den1;
    int den = den1 * den2;
    int g = gcd(num, den);
    num /= g;
    den /= g;

    cout << num << " " << den << "\n";
}