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

    long long value;
    cin >> value;

    if (value % 2)
        cout << value * value * value;
    else
        cout << value * value;
}