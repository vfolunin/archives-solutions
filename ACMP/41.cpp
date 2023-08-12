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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> count(201);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value + 100]++;
    }

    for (int i = 0; i < count.size(); i++)
        for (int j = 0; j < count[i]; j++)
            cout << i - 100 << " ";
}