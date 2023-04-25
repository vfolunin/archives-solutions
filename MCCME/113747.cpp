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

    int kilometers, minutes, callPrice, kilometerPrice, minutePrice;
    cin >> kilometers >> minutes >> callPrice >> kilometerPrice >> minutePrice;

    cout << callPrice + kilometers * kilometerPrice + minutes * minutePrice;
}