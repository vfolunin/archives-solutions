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
    cout << setw(2) << setfill('0') << time / 3600 << ":";
    cout << setw(2) << setfill('0') << time % 3600 / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int songCount, fade;
    cin >> songCount >> fade;

    int time = 0;
    for (int i = 0; i < songCount; i++)
        time += readTime();

    time -= (songCount - 1) * fade;

    writeTime(time);
}