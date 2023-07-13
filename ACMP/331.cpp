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
    int h, m;
    cin >> h >> m;

    int t2 = (t1 + h * 60 + m) % (24 * 60);

    writeTime(t2);
}