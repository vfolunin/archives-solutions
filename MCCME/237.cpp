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

    int a, b, c, ab, ac, bc, abc;
    cin >> a >> b >> c >> ab >> ac >> bc >> abc;

    cout << a + b + c - ab - ac - bc + abc;
}