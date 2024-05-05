#include <iostream>
#include <algorithm>
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

    deque<int> a;
    for (int value = 1; value <= size; value++) {
        if (value % 2)
            a.push_back(value);
        else
            a.push_front(value);
    }

    if (size % 2)
        reverse(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
}