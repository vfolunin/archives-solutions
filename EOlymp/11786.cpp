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

    int size, queryCount;
    cin >> size >> queryCount;

    deque<int> values(size);
    for (int &value : values)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        int value = values.front() + values.back();
        values.pop_front();
        values.push_back(value);
    }

    for (int &value : values)
        cout << value << " ";
}