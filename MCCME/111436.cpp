#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    int res = -1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (res == -1 || digitSum(res) < digitSum(value))
            res = value;
    }

    cout << res;
}