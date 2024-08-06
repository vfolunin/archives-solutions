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

    int sum;
    cin >> sum;

    for (int a = sum, b = 0; b <= sum; a -= 2, b += 2)
        if (b % 4 == 0)
            cout << a << " " << b << "\n";
}