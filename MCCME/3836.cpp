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

    int value, minOdd = 0;
    
    while (cin >> value)
        if (value % 2 && (!minOdd || minOdd > value))
            minOdd = value;

    cout << minOdd;
}