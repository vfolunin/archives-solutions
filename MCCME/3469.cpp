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

    int t;
    cin >> t;

    t %= 24 * 3600;

    cout << t / 3600 << ":";
    cout << setw(2) << setfill('0') << t % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60;
}