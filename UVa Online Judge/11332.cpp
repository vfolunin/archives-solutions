#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int g(long long n) {
    if (n < 10)
        return n;
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return g(sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1) {
        int n;
        cin >> n;
        if (!n)
            break;
        cout << g(n) << "\n";
    }
}