#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int examCount, pointSum, minPoint;
    cin >> examCount >> pointSum >> minPoint;

    vector<vector<long long>> ways(examCount + 1, vector<long long>(pointSum + 1));
    ways[0][0] = 1;

    for (int exam = 0; exam < examCount; exam++)
        for (int sum = 0; sum <= pointSum; sum++)
            if (ways[exam][sum])
                for (int point = minPoint; sum + point <= pointSum; point++)
                    ways[exam + 1][sum + point] += ways[exam][sum];
    
    cout << ways[examCount][pointSum] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}