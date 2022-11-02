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

    while (cin.peek() != '\n') {
        int value;
        cin >> value;
        a.push_back(value);
    }

    int index, value;
    cin >> index >> value;

    a.insert(a.begin() + index, value);

    for (int value : a)
        cout << value << " ";
}