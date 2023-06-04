#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int days, startDay;
    cin >> days >> startDay;

    if (days == 28 && startDay == 1)
        cout << 4;
    else if (days == 30 && startDay == 7 || days == 31 && startDay >= 6)
        cout << 6;
    else
        cout << 5;
}