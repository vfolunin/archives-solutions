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

    for (int i = 0; i < a.size(); i++) {
        if (i == 0 || i == a.size() - 1) {
            cout << a[i] << " ";
        } else {
            int sum = a[i - 1] + a[i + 1];
            cout << (sum < 0 ? "-" : "") << abs(sum / 2) << (sum % 2 ? ".5 " : ".0 ");
        }
    }
}