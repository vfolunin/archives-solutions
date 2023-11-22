#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes, seconds;
    char colon;
    cin >> hours >> colon >> minutes >> colon >> seconds;

    return hours * 3600 + minutes * 60 + seconds;
}

void writeTime(int time) {
    cout << setw(2) << setfill('0') << time / 3600 << ":";
    cout << setw(2) << setfill('0') << time % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = readTime();
    int b = readTime();

    if (b < a)
        b += 24 * 3600;

    writeTime(b - a);
}