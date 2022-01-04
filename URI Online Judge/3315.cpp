#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toBinary(int n) {
    string bin;
    while (n >= 2) {
        bin += '0' + n % 2;
        n /= 2;
    }
    bin += '0' + n % 2;
    reverse(bin.begin(), bin.end());
    return bin;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> sums(4);
    for (int &sum : sums) {
        for (int i = 0; i < 7; i++) {
            int x;
            cin >> x;
            sum += x;
        }
    }

    int maxSum = *max_element(sums.begin(), sums.end());

    cout << maxSum << " = " << toBinary(maxSum) << "\n";
}