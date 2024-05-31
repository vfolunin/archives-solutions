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

    int sum;
    cin >> sum;

    bool found = 0;
    for (int i = 10; i * i < 1000; i++) {
        if (digitSum(i * i) == sum) {
            cout << i * i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << "No";
}