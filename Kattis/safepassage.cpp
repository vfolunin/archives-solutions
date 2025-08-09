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

    int size;
    cin >> size;

    vector<int> time(size);
    for (int &t : time)
        cin >> t;

    sort(time.begin(), time.end());

    int totalTime = 0;
    while (time.size() > 3) {
        int &a = time[0];
        int &b = time[1];
        int &y = time[time.size() - 2];
        int &z = time[time.size() - 1];

        totalTime += min(b + a + z + b, y + a + z + a);

        time.pop_back();
        time.pop_back();
    }

    if (time.size() == 1)
        totalTime += time[0];
    else if (time.size() == 2)
        totalTime += time[1];
    else
        totalTime += time[0] + time[1] + time[2];

    cout << totalTime;
}