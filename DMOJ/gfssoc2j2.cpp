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

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0, value = i; j < 2; j++, value += i - 1) {
            if (value % 91 == 0)
                cout << "Fizz Fuzz";
            else if (value % 7 == 0)
                cout << "Fizz";
            else if (value % 13 == 0)
                cout << "Fuzz";
            else
                cout << value;
            cout << (j ? "\n" : " ");
        }
    }
}