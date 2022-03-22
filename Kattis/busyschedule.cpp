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
    string half;
    cin >> h >> colon >> m >> half;

    if (h == 12)
        h = 0;

    if (half == "p.m.")
        h += 12;
    
    return h * 60 + m;
}

void writeTime(int t) {
    int h = t / 60, m = t % 60;
    string half = "a.m.";

    if (h >= 12) {
        h -= 12;
        half = "p.m.";
    }

    if (!h)
        h = 12;

    cout << h << ":" << setw(2) << setfill('0') << m << " " << half << "\n";
}

bool solve(int test) {
    int timeCount;
    cin >> timeCount;

    if (!timeCount)
        return 0;

    vector<int> times(timeCount);
    for (int &time : times)
        time = readTime();

    sort(times.begin(), times.end());

    if (test)
        cout << "\n";
    for (int time : times)
        writeTime(time);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}