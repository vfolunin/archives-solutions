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

    int size, parallelCount, finishedCount;
    cin >> size >> parallelCount >> finishedCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    double num = 0, den = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i < parallelCount + finishedCount)
            num += a[i];
        den += a[i];
    }

    cout << fixed << num / den * 100;
}