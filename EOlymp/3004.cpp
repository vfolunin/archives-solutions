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

    int customerCount, windowCount;
    cin >> customerCount >> windowCount;

    multiset<long long> windows;
    for (int i = 0; i < windowCount; i++)
        windows.insert(0);

    for (int i = 0; i < customerCount; i++) {
        long long time;
        cin >> time;

        time += *windows.begin();
        windows.erase(windows.begin());
        windows.insert(time);
    }

    cout << *windows.rbegin();
}