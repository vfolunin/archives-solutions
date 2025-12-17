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

    int a, b, limit;
    cin >> a >> b >> limit;

    if (a > limit)
        cout << "Bob overdoses on day 1.";
    else if (a + 2 * b > 2 * limit)
        cout << "Bob overdoses on day 2.";
    else
        cout << "Bob never overdoses.";
}