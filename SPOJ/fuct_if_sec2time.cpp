#include <iostream>
#include <iomanip>
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

    if (n >= 0) {
        cout << setw(2) << setfill('0') << n / 3600 << ":";
        cout << setw(2) << setfill('0') << n % 3600 / 60 << ":";
        cout << setw(2) << setfill('0') << n % 60;
    } else {
        cout << "total second must be a positive integer";
    }
}