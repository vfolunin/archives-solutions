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

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    reverse(a.begin(), a.begin() + a.size() / 2);
    reverse(a.begin() + a.size() / 2, a.end());

    for (int value : a)
        cout << value << " ";
}