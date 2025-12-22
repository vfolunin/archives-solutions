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

    for (int value : { 0, 10001, 10101, 10201, 10301, 11011, 11111, 11211, 12021, 13031 })
        cout << value << "\n";
}