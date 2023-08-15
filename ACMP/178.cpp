#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> count;
    int maxCount = 0, maxCountValue;

    for (int &value : a) {
        cin >> value;
        count[value]++;
        if (maxCount < count[value] || maxCount == count[value] && maxCountValue > value) {
            maxCount = count[value];
            maxCountValue = value;
        }
    }

    for (int value : a)
        if (value != maxCountValue)
            cout << value << " ";

    for (int i = 0; i < maxCount; i++)
        cout << maxCountValue << " ";
}