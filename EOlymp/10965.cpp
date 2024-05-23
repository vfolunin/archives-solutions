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

    for (int d : { 3, 5, 7 })
        cout << (n / 100 % d == 0 && n % 100 % d == 0 ? "Yes\n" : "No\n");
}