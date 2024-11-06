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

    int num, den, interval, time;
    cin >> num >> den >> interval >> time;

    cout << min((time / interval + 1) * den, num);
}