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

    long long squareSum;
    cin >> squareSum;

    long long sum = 0;
    for (int i = 1; 1; i++) {
        sum += i * i;
        if (sum == squareSum) {
            cout << i;
            break;
        }
    }
}