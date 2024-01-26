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

    int maxValue = *max_element(a.begin(), a.end());

    for (int value : a)
        if (value != maxValue)
            cout << value << " ";

    for (int value : a)
        if (value == maxValue)
            cout << value << " ";
}