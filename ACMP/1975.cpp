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

    writeTime(24 * 60 - t1 + t2);
}