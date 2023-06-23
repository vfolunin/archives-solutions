#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    char colon;
    cin >> h >> colon >> m;
    return h * 60 + m;
}

void writeTime(int t) {
    int h = t / 60, m = t % 60;
    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();
    int t3 = readTime();
    int t4 = readTime();

    int t12 = t2 - t1;
    if (t12 < 0)
        t12 += 24 * 60;

    int t34 = t4 - t3;
    if (t34 < 0)
        t34 += 24 * 60;

    int t = (t12 + t34 + 1) / 2 % (12 * 60);
    if (!t)
        t = 12 * 60;

    writeTime(t);
}