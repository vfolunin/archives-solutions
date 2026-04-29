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

    int problemCount, tripTime;
    cin >> problemCount >> tripTime;

    int res = 0;
    while (res < problemCount && 5 * (res + 1) * (res + 2) / 2 + tripTime <= 240)
        res++;

    cout << res;
}