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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> has(size);
    int maxValueCount = 0, curValueCount = 0;
    for (int i = 0, neededValue = 0; i < size; i++) {
        int value;
        cin >> value;
        value--;

        has[value] = 1;
        curValueCount++;
        while (neededValue < has.size() && has[neededValue]) {
            neededValue++;
            curValueCount--;
        }

        maxValueCount = max<int>(maxValueCount, curValueCount);
    }

    cout << maxValueCount;
}