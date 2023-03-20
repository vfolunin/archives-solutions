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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int time = readTime();

    time = (time + 132) % (24 * 60);

    cout << setw(2) << setfill('0') << time / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}