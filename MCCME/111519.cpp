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

    int sum = 0;
    for (int i = 0; i < a.size() || sum; i++) {
        if (i < a.size())
            sum += a[i];
        if (sum) {
            cout << "+ ";
            sum--;
        } else {
            cout << "- ";
        }
    }
}