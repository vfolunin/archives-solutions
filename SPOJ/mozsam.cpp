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

    long long res = 1;
    vector<int> negative;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0)
            res *= value;
        else if (value < 0)
            negative.push_back(value);
    }

    sort(negative.rbegin(), negative.rend());
    for (int i = negative.size() % 2; i < negative.size(); i++)
        res *= negative[i];

    cout << res;
}