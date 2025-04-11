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

    int sum1 = 0;
    for (int i = 0; i < 3; i++) {
        int value;
        cin >> value;
        sum1 += value;
    }

    int sum2 = 0;
    for (int i = 0; i < 3; i++) {
        int value;
        cin >> value;
        sum2 += value;
    }

    int target;
    cin >> target;

    if (abs(sum1 - target) < abs(sum2 - target) ||
        abs(sum1 - target) == abs(sum2 - target) && sum1 >= sum2)
        cout << "1\n" << sum1;
    else
        cout << "2\n" << sum2;
}