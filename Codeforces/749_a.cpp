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
    cin >> value;

    cout << value / 2 << "\n" << 2 + value % 2 << " ";
    for (int i = 1; i < value / 2; i++)
        cout << "2 ";
}