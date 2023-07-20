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

    for (int i = 0; i < den - num % den; i++)
        cout << num / den << " ";
    for (int i = 0; i < num % den; i++)
        cout << num / den + 1 << " ";
}