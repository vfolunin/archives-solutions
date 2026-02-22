#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int time) {
    time %= 12 * 60;
    int hours = time / 60, minutes = time % 60;
    if (!hours)
        hours = 12;

    string sHours = to_string(hours);
    string sMinutes = to_string(minutes);
    sMinutes = string(2 - sMinutes.size(), '0') + sMinutes;

    string s = sHours + sMinutes;
    for (int i = 2; i < s.size(); i++)
        if (s[i] - s[i - 1] != s[1] - s[0])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int minuteCount;
    cin >> minuteCount;

    int cycleRes = 0;
    for (int i = 0; i < 12 * 60; i++)
        cycleRes += isGood(i);

    int res = minuteCount / (12 * 60) * cycleRes;

    minuteCount %= 12 * 60;
    for (int i = 0; i <= minuteCount; i++)
        res += isGood(i);

    cout << res;
}