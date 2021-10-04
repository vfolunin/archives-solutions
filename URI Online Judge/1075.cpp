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

    int mod;
    cin >> mod;

    for (int i = 1; i <= 10000; i++)
        if (i % mod == 2)
            cout << i << "\n";
}