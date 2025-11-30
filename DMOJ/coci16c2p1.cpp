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

    int totalCount = 0, maxCount = 0;
    string maxName;

    for (int i = 0; i < size; i++) {
        string name;
        int need, have;
        cin >> name >> need >> have;

        int count = 0;
        while (have >= need) {
            count++;
            have = have - need + 2;
        }

        totalCount += count;
        if (maxCount < count) {
            maxCount = count;
            maxName = name;
        }
    }

    cout << totalCount << "\n" << maxName;
}