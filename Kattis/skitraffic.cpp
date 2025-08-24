#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string name;
    getline(cin, name);

    int hours, minutes, flag1, flag2, flag3;
    char colon;
    string weekday;
    cin >> hours >> colon >> minutes >> weekday >> flag1 >> flag2 >> flag3;

    int time = hours * 60 + minutes;

    if (weekday == "sat" || weekday == "sun")
        time *= 2;
    if (flag1)
        time *= 2;
    if (flag2)
        time *= 3;
    if (flag3)
        time *= 3;

    cout << time / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}