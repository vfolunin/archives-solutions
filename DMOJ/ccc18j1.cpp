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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a == 8 || a == 9) && b == c && (d == 8 || d == 9))
        cout << "ignore";
    else
        cout << "answer";
}