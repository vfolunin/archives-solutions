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

    double prize, bet, p;
    cin >> prize >> bet >> p;

    cout << (prize * p >= bet ? "spela inte!" : "spela");
}