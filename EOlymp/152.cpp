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

    long long n;
    cin >> n;

    long long add = n * n - n * (n + 1) / 2;
    if (add % 2)
        add += n;

    cout << (add % 2 == 0 ? add / 2 : -1);
}