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

    int pos = *max_element(a.begin(), a.end()) / 2;
    int neg = *min_element(a.begin(), a.end()) / 2;

    for (int value : a) {
        if (value)
            cout << value - (value > 0 ? pos : neg) << " ";
        else
            cout << "0 ";
    }
}