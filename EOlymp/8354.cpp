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
 
    int targetSum;
    cin >> targetSum;

    vector<string> res(targetSum + 1);
    for (int sum = 1; sum <= targetSum; sum++) {
        for (int digit = 9; digit >= 1; digit--) {
            if (sum >= digit * digit * digit) {
                string candidate = res[sum - digit * digit * digit] + string(1, digit + '0');
                sort(candidate.begin(), candidate.end());

                if (res[sum].empty() || res[sum].size() > candidate.size() ||
                    res[sum].size() == candidate.size() && res[sum] > candidate)
                    res[sum] = candidate;
            }
        }
    }

    cout << res[targetSum];
}