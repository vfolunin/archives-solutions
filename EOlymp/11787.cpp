#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    deque<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (i % 2)
            values.push_front(value);
        else
            values.push_back(value);
    }

    if (values.size() % 2)
        reverse(values.begin(), values.end());

    for (int value : values)
        cout << value << " ";
}