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

    unsigned long long n;
    cin >> n;

    unsigned long long ceil = 1;
    while (ceil <= n)
        ceil *= 2;

    cout << ceil - 1 - n;
}