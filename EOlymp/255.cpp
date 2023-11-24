#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitRoot(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitRoot(sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << digitRoot(n);
}