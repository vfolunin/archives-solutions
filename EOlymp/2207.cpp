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
    t %= 24 * 60;
    int h = t / 60, m = t % 60;
    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = readTime();

    int stationCount;
    cin >> stationCount;

    writeTime(t);
    cout << "\n";

    for (int i = 1; i < stationCount; i++) {
        int delta;
        cin >> delta;
        t += delta;

        writeTime(t);
        cout << "\n";
    }
}