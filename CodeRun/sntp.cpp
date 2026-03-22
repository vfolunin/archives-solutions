#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m, s;
    char colon;
    cin >> h >> colon >> m >> colon >> s;
    return h * 60 * 60 + m * 60 + s;
}

void writeTime(int t) {
    int h = t / (60 * 60), m = t / 60 % 60, s = t % 60;
    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << ":";
    cout << setw(2) << setfill('0') << s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = readTime();
    int b = readTime();
    int c = readTime();

    if (a > c)
        c += 24 * 60 * 60;

    b = (b + (c - a + 1) / 2) % (24 * 60 * 60);

    writeTime(b);
}