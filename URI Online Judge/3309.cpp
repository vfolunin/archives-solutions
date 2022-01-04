#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isHappy(int n) {
    if (n == 1)
        return 1;
    if (n == 4 || n == 9)
        return 0;

    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return isHappy(sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        res += isHappy(x);
    }

    cout << res << "\n";
}