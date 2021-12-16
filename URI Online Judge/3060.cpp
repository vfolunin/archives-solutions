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

    int num, den;
    cin >> num >> den;

    int ratio = num / den, remainder = num % den;

    for (int i = 0; i < remainder; i++)
        cout << ratio + 1 << "\n";
    for (int i = remainder; i < den; i++)
        cout << ratio << "\n";
}