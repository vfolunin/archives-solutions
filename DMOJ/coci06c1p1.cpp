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

    set<int> numbers;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        numbers.insert(x % 42);
    }

    cout << numbers.size();
}