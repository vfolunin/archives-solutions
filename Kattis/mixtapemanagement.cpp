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

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        string s = to_string(i);
        s = string(3 - s.size(), '0') + s;

        cout << "1" << s << string(value, '0') << " ";
    }
}