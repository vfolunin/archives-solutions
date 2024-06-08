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

    int size, palindromeSize;
    cin >> size >> palindromeSize;

    cout << string(palindromeSize, 'A');
    for (int i = palindromeSize; i < size; i++)
        cout << (char)('B' + i % 3);
}