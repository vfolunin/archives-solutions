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

    int num1, num2, den, a, b;
    cin >> num1 >> num2 >> den >> a >> b;

    int bonus1 = num1 / den * a - (num1 % den ? b : 0);
    int bonus2 = num2 / den * a - (num2 % den ? b : 0);

    if (bonus1 >= bonus2)
        cout << "1 " << bonus1;
    else
        cout << "2 " << bonus2;
}