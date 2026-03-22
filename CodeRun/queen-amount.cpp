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

    vector<int> a(4);
    int totalSum = 0;
    for (int &value : a) {
        cin >> value;
        totalSum += value;
    }

    if (totalSum < 2) {
        cout << 1;
        return 0;
    }

    sort(a.begin(), a.end());

    int correctSum = 0, correctCount = 0;
    while (correctCount < 4 && correctSum + a[correctCount] <= 4) {
        correctSum += a[correctCount];
        correctCount++;
    }

    cout << 4 - correctCount;
}