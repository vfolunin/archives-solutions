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

    cout << n / 365 << " ano(s)\n";
    cout << n % 365 / 30 << " mes(es)\n";
    cout << n % 365 % 30 << " dia(s)\n";
}