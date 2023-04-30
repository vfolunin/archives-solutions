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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int maxIndex = max_element(a.begin(), a.end()) - a.begin();

    int resValue = -1;
    for (int i = maxIndex + 1; i + 1 < a.size(); i++)
        if (a[i] % 10 == 5 && a[i] > a[i + 1] && (resValue == -1 || resValue < a[i]))
            resValue = a[i];

    if (resValue == -1) {
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());
    cout << a.end() - upper_bound(a.begin(), a.end(), resValue) + 1;
}