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

    int taskCount, limit;
    cin >> taskCount >> limit;

    int sum = 0;
    for (int i = 0; i < taskCount; i++) {
        int task;
        cin >> task;

        sum += task;
        if (sum > limit) {
            cout << i;
            return 0;
        }
    }

    cout << taskCount;
}