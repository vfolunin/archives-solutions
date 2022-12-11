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

    vector<int> a(5);
    for (int &value : a)
        cin >> value;

    int minIndex = min_element(a.begin(), a.end()) - a.begin();
    int maxIndex = a.size() - 1 - (max_element(a.rbegin(), a.rend()) - a.rbegin());

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i == minIndex || i == maxIndex) {
            cout << "(" << a[i] << ") ";
        } else {
            cout << a[i] << " ";
            sum += a[i];
        }
    }
    cout << "= " << sum;
}