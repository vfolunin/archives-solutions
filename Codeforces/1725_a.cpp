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

    long long height, width;
    cin >> height >> width;

    if (width == 1)
        cout << height - 1;
    else
        cout << height * (width - 1);
}