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

    int limit, farmCount, checkCount;
    cin >> limit >> farmCount >> checkCount;

    vector<long long> farms(1001);
    for (int i = 0; i < farmCount; i++) {
        int cowCount;
        cin >> cowCount;
        farms[cowCount]++;
    }

    vector<long long> totalFarms(51);
    totalFarms[0] = farmCount;

    for (int i = 1; i < totalFarms.size(); i++) {
        vector<long long> nextFarms(1001);
        for (int j = 0; j < farms.size(); j++) {
            if (j * 2 <= limit)
                nextFarms[j * 2] += farms[j];
            else
                nextFarms[j] += 2 * farms[j];
        }
        farms.swap(nextFarms);
        for (int j = 0; j < farms.size(); j++)
            totalFarms[i] += farms[j];
    }

    for (int i = 0; i < checkCount; i++) {
        int day;
        cin >> day;
        cout << totalFarms[day] << "\n";
    }
}