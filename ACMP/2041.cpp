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

    int count = 0, maxSum = -1e9;
    for (int i = 0, j = 3; j < a.size(); i++, j++) {
        if ((abs(a[i]) % 100 == 13) ^ (abs(a[j]) % 100 == 13)) {
            count++;
            maxSum = max(maxSum, a[i] + a[j]);
        }
    }

    cout << count << " " << maxSum;
}