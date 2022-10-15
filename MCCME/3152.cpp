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
    for (int i = 0; cin >> value; i++)
        if (i % 2 == 0)
            cout << value << " ";
}