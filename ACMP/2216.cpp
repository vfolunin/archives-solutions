#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    char colon;
    cin >> hours >> colon >> minutes;

    return hours * 60 + minutes;
}

void writeTime(int time) {
    cout << setw(2) << setfill('0') << time / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();

    int minutes = t2 - t1;
    if (minutes < 0)
        minutes += 24 * 60;

    int delta;
    cin >> delta;

    minutes = minutes * 60 / (60 + delta);

    writeTime((t1 + minutes) % (24 * 60));
}