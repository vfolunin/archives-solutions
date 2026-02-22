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

bool isRushHour(int time) {
    return 7 * 60 <= time && time < 10 * 60 || 15 * 60 <= time && time < 19 * 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int time = readTime(), distance = 2 * 60 * 2;

    while (distance > 0) {
        distance -= isRushHour(time) ? 1 : 2;
        time = (time + 1) % (24 * 60);
    }

    writeTime(time);
}