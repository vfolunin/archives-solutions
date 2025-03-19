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

    vector<int> order;
    for (int i; cin >> i; ) {
        order.push_back(i);
        if (cin.peek() == '\n')
            break;
    }

    vector<string> values;
    for (string value; cin >> value; )
        values.push_back(value);

    for (int i : order)
        cout << values[i] << " ";
}