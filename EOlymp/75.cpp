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

    int value, sum;
    cin >> value >> sum;
    
    for (int count = 2; 1; count++) {
        int curSum = value;
        for (int i = 1; i < count; i++)
            curSum += value + i;
        curSum += value + count - 1;

        if (curSum == sum) {
            cout << count;
            break;
        }
    }
}