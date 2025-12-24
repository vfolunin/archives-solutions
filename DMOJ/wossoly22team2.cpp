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

    vector<int> res(25);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        for (int j = 2; j < res.size(); j++)
            res[j] += value / j * j;
    }

    cout << *max_element(res.begin(), res.end());
}