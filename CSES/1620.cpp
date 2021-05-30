#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<long long> &time, long long totalTime, long long productCount) {
    long long productMade = 0;
    for (long long t : time)
        productMade += totalTime / t;
    return productMade >= productCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int machineCount, productCount;
    cin >> machineCount >> productCount;

    vector<long long> time(machineCount);
    for (long long &t : time)
        cin >> t;

    long long l = 0, r = *min_element(time.begin(), time.end()) * productCount;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(time, m, productCount))
            r = m;
        else
            l = m;
    }

    cout << r;
}