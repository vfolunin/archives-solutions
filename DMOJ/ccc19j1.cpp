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

    int a3, a2, a1, b3, b2, b1;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;

    int aScore = a3 * 3 + a2 * 2 + a1;
    int bScore = b3 * 3 + b2 * 2 + b1;

    if (aScore > bScore)
        cout << "A";
    else if (aScore == bScore)
        cout << "T";
    else
        cout << "B";
}