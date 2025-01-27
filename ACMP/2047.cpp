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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    int minValueRemainder = *min_element(a.begin(), a.end()) % 3;
    int maxValueRemainder = *max_element(a.begin(), a.end()) % 7;

    int count = 0, maxSum = -1e9;
    for (int i = 0; i + 1 < a.size(); i++) {
        if ((a[i] % 3 == minValueRemainder || a[i + 1] % 3 == minValueRemainder) &&
            (a[i] % 7 == maxValueRemainder || a[i + 1] % 7 == maxValueRemainder)) {
            count++;
            maxSum = max(maxSum, a[i] + a[i + 1]);
        }
    }

    cout << count << " " << maxSum;
}