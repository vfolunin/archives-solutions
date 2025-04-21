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

    int count10, count50, count100;
    cin >> count10 >> count50 >> count100;

    int change = count50 * 40 + count100 * 90;

    int delta = min(count50, count100);
    change -= delta * 50;
    count50 -= delta;

    delta = min(count10, change / 10);
    count10 -= delta;

    cout << count10 + count50 + count100;
}