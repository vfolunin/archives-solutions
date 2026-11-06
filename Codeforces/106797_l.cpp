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

    for (int i = 0; i < size; i++)
        cout << (char)(i < palindromeSize ? 'a' : 'b' + i % 3);
}