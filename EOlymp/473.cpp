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

    int maxIndex = max_element(a.begin(), a.end()) - a.begin();

    for (int i = maxIndex - 1; i >= 0; i--) {
        if (a[i] >= a[i + 1]) {
            cout << "no";
            return 0;
        }
    }

    for (int i = maxIndex + 1; i < a.size(); i++) {
        if (a[i] >= a[i - 1]) {
            cout << "no";
            return 0;
        }
    }

    cout << "yes";
}