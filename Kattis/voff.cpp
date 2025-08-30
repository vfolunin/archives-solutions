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

    int size, gap;
    cin >> size >> gap;

    multiset<int> times;
    for (int i = 0; i < size; i++) {
        int time;
        cin >> time;

        if (!times.empty() && *times.begin() + gap <= time)
            times.erase(times.begin());
        times.insert(time);
    }

    cout << times.size();
}