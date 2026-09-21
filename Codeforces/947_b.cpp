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
 
    int dayCount;
    cin >> dayCount;

    vector<int> volumes(dayCount);
    for (int &volume : volumes)
        cin >> volume;

    multiset<long long> volumeQueue;
    long long totalDelta = 0;

    for (int i = 0; i < dayCount; i++) {
        volumeQueue.insert(volumes[i] + totalDelta);

        int delta;
        cin >> delta;

        long long res = 0;
        while (!volumeQueue.empty() && *volumeQueue.begin() - totalDelta <= delta) {
            res += *volumeQueue.begin() - totalDelta;
            volumeQueue.erase(volumeQueue.begin());
        }
        res += volumeQueue.size() * delta;

        cout << res << " ";

        totalDelta += delta;
    }
}