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

    int dayCount;
    cin >> dayCount;

    vector<int> balance(2), minBalance(2);
    
    for (int day = 0; day < dayCount; day++) {
        vector<string> rain(2);
        cin >> rain[0] >> rain[1];

        for (int i = 0; i < 2; i++) {
            if (rain[i] == "chuva") {
                balance[i]--;
                balance[!i]++;
            }
            for (int j = 0; j < 2; j++)
                minBalance[j] = min(minBalance[j], balance[j]);
        }
    }

    cout << -minBalance[0] << " " << -minBalance[1] << "\n";
}