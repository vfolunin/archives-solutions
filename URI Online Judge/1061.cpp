#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    string buf;
    int d, h, m, s;
    cin >> buf >> d >> h >> buf >> m >> buf >> s;
    return ((d * 24 + h) * 60 + m) * 60 + s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();
    int t = t2 - t1;

    cout << t / (24 * 60 * 60) << " dia(s)\n";
    t %= 24 * 60 * 60;
    cout << t / (60 * 60) << " hora(s)\n";
    t %= 60 * 60;
    cout << t / 60 << " minuto(s)\n";
    t %= 60;
    cout << t << " segundo(s)\n";
}