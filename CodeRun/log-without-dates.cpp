#include <iostream>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int timeCount;
    cin >> timeCount;

    int prevTime = -1, days = 1;
    for (int i = 0; i < timeCount; i++) {
        int time = readTime();
        days += prevTime >= time;
        prevTime = time;
    }

    cout << days;
}