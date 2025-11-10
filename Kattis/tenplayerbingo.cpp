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

    int value;
    for (int i = 0; i < 100; i++)
        cin >> value;

    cout << (value % 10 ? value % 10 : 10);
}