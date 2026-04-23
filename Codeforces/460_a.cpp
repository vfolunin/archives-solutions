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

    int count, divisor;
    cin >> count >> divisor;

    for (int day = 1; 1; day++) {
        if (!count) {
            cout << day - 1;
            break;
        }
        count--;
        count += day % divisor == 0;
    }
}