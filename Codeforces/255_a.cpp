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

    vector<int> sum(3);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum[i % 3] += value;
    }

    vector<string> res = { "chest", "biceps", "back" };

    cout << res[max_element(sum.begin(), sum.end()) - sum.begin()];
}