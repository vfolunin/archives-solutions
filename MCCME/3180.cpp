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

    int d;
    cin >> d;

    for (int i = d; i <= 26; i += d)
        cout << (char)(i - 1 + 'a') << " ";
}