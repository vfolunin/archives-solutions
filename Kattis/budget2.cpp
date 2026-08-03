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

    int budget, a, b, c;
    cin >> budget >> a >> b >> c;

    cout << "Budget is " << (budget >= a + b + c ? "sufficient." : "insufficient.");
}