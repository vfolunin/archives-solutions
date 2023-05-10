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

    int product = 1;

    while (isdigit(cin.peek())) {
        int value;
        cin >> value;
        cin.get();
        product *= value;
    }

    cout << product;
}