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

    long long shotCount, capacity, reloadAllTime, reload1Time;
    cin >> shotCount >> capacity >> reloadAllTime >> reload1Time;

    long long t1 = (shotCount + capacity - 1) / capacity * reloadAllTime;
    long long t2 = shotCount / capacity * reloadAllTime + shotCount % capacity * reload1Time;
    long long t3 = shotCount * reload1Time;

    cout << shotCount + min({ t1, t2, t3 });
}