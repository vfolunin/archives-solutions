#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(int n) {
    while (n) {
        if (n % 10 == 3 || n % 10 == 4)
            return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    n++;
    while (!check(n))
        n++;

    cout << n;
}