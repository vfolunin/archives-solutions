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

    int h, m;
    char colon;
    string part;
    cin >> h >> colon >> m >> part;

    if ((h == 12) ^ (part == "p.m."))
        h += 12;
    h %= 24;

    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m;
}