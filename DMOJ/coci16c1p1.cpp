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

    int limit, monthCount;
    cin >> limit >> monthCount;

    int available = limit;
    for (int i = 0; i < monthCount; i++) {
        int spent;
        cin >> spent;
        available += limit - spent;
    }

    cout << available;
}