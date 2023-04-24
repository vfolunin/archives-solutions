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

    for (int coin : { 5000, 1000, 500, 100, 50, 10, 5, 2, 1 }) {
        if (n / coin % 2) {
            cout << "NO";
            return 0;
        }
        n %= coin;
    }
    
    cout << "YES";
}