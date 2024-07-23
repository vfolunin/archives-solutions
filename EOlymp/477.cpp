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

    long long sum;
    cin >> sum;

    for (long long a = -2e4; a <= 2e4; a++)
        for (long long b = a; b <= 2e4; b++)
            if (a * a * a + b * b * b == sum)
                cout << a << " " << b << "\n";
}