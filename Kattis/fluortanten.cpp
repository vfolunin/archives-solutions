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

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    a.erase(remove(a.begin(), a.end(), 0), a.end());

    long long curScore = 0;
    for (int i = 0; i < a.size(); i++)
        curScore += (i + 1) * a[i];

    long long maxScore = curScore;
    for (int i = a.size() - 1; i >= 0; i--) {
        curScore += a[i];
        maxScore = max(maxScore, curScore);
    }

    cout << maxScore;
}