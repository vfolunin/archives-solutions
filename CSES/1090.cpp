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

    int childCount, weightLimit;
    cin >> childCount >> weightLimit;

    vector<int> weight(childCount);
    for (int &w : weight)
        cin >> w;
    sort(weight.begin(), weight.end());

    int gondolaCount = 0;
    for (int l = 0, r = weight.size() - 1; l <= r; r--) {
        if (l <= r && weight[l] + weight[r] <= weightLimit)
            l++;
        gondolaCount++;
    }

    cout << gondolaCount;
}