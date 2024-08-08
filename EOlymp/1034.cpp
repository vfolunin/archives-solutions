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

    int num1, den1, den2, num3, den3;
    char c;
    cin >> num1 >> c >> den1 >> c >> c >> den2 >> num3 >> c >> den3;

    int num2 = 0;
    while (num1 * den2 >= num2 * den1)
        num2++;

    if (num2 * den3 < num3 * den2)
        cout << num2 << "/" << den2;
    else
        cout << -1;
}