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

    int h1, m1, s1, h2, m2, s2;
    char colon;
    cin >> h1 >> colon >> m1 >> colon >> s1;
    cin >> h2 >> colon >> m2 >> colon >> s2;

    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    if (t2 <= t1)
        t2 += 24 * 3600;
    int t = t2 - t1;

    cout << setw(2) << setfill('0') << t / 3600 << ":";
    cout << setw(2) << setfill('0') << t % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60;
}