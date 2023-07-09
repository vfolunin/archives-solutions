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

    vector<int> a(3);
    for (int &value : a) {
        cin >> value;

        if (value < 94 || value > 727) {
            cout << "Error";
            return 0;
        }
    }

    cout << *max_element(a.begin(), a.end());
}