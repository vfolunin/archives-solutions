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

    int den, time, num;
    cin >> den >> time >> num;

    if (num <= den)
        cout << 2 * time;
    else
        cout << (num * 2 + den - 1) / den * time;
}