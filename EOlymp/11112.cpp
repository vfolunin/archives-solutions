#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int next(int value) {
    string s = to_string(value);

    sort(s.begin(), s.end());
    int minValue = stoi(s);

    reverse(s.begin(), s.end());
    int maxValue = stoi(s);

    return maxValue - minValue;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value, index;
    cin >> value >> index;

    for (int i = 0; i < index; i++)
        value = next(value);

    cout << value;
}