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

    int size;
    cin >> size;

    int maxSum = size * 9;
    vector<vector<vector<int>>> ways(size + 1, vector<vector<int>>(maxSum + 1, vector<int>(maxSum + 1)));
    vector<vector<vector<string>>> minValue(size + 1, vector<vector<string>>(maxSum + 1, vector<string>(maxSum + 1, "A")));

    for (int digit = 0; digit <= 9; digit++) {
        ways[1][digit][digit] = 1;
        minValue[1][digit][digit] = string(1, digit + '0');
    }

    for (int len = 1; len < size; len++) {
        for (int sum = 1; sum <= len * 9; sum++) {
            for (int product = 0; product <= maxSum; product++) {
                for (int digit = 0; digit <= 9 && product * digit <= maxSum; digit++) {
                    ways[len + 1][sum + digit][product * digit] += ways[len][sum][product];
                    minValue[len + 1][sum + digit][product * digit] = min(
                        minValue[len + 1][sum + digit][product * digit],
                        minValue[len][sum][product] + (char)(digit + '0')
                    );
                }
            }
        }
    }

    int resWays = 0;
    string resMinValue = "A";
    for (int sum = 0; sum <= maxSum; sum++) {
        resWays += ways[size][sum][sum];
        resMinValue = min(resMinValue, minValue[size][sum][sum]);
    }

    cout << resWays << " " << resMinValue;
}