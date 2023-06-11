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

    bool found = 0;
    double maxValue = -1;
    int maxValueIndex;

    for (int i = 1; i <= size; i++) {
        double value;
        cin >> value;

        if (value > 1) {
            cout << i << " ";
            found = 1;
        }
        if (maxValue < value) {
            maxValue = value;
            maxValueIndex = i;
        }
    }

    if (!found)
        cout << maxValueIndex;
}