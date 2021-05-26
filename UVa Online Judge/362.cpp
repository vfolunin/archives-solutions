#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<int> parts;
    int sum = 0;
    do {
        parts.emplace_back();
        cin >> parts.back();
        sum += parts.back();
    } while (sum < size);

    cout << "Output for data set " << test << ", " << size << " bytes:\n";

    for (int i = 4; i < parts.size(); i += 5) {
        int sum = 0;
        for (int j = i - 4; j <= i; j++) {
            size -= parts[j];
            sum += parts[j];
        }

        cout << "   Time remaining: ";
        cout.precision(0);
        if (sum)
            cout << fixed << ceil(5.0 * size / sum) << " seconds\n";
        else
            cout << "stalled\n";
    }

    cout << "Total time: " << parts.size() << " seconds\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}