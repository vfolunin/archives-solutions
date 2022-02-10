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

    int teamCount;
    cin >> teamCount;

    long long sumTime = 0;
    int maxTime = 0;
    for (int i = 0; i < teamCount; i++) {
        int time;
        cin >> time;
        sumTime += time;
        maxTime = max(maxTime, time);
    }

    cout << max(sumTime, maxTime * 2LL);
}