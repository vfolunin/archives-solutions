#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    bool found = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (isPrime(value)) {
            cout << value << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}