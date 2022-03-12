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

    int n;
    cin >> n;

    while (n >= 10) {
        int nextN = 1;
        while (n) {
            if (n % 10)
                nextN *= n % 10;
            n /= 10;
        }
        n = nextN;
    }

    cout << n;
}