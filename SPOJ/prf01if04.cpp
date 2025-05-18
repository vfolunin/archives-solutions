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

    cout << "Please enter a number divisible by 5 and divisible by 2:";

    int n;
    cin >> n;

    if (n % 10 == 0)
        cout << "Thank you.";
    else
        cout << n << " isn't a number divisible by 5 and divisible by 2.";
}