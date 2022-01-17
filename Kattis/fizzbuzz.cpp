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

    int a, b, n;
    cin >> a >> b >> n;

    for (int i = 1; i <= n; i++) {
        if (i % a == 0 && i % b == 0)
            cout << "FizzBuzz\n";
        else if (i % a == 0)
            cout << "Fizz\n";
        else if (i % b == 0)
            cout << "Buzz\n";
        else
            cout << i << "\n";
    }
}