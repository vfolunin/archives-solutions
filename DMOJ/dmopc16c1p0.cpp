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

    int a, b;
    cin >> a >> b;

    if (a == 3 && 95 <= b)
        cout << "C.C. is absolutely satisfied with her pizza.";
    else if (a == 1 && b <= 50)
        cout << "C.C. is fairly satisfied with her pizza.";
    else
        cout << "C.C. is very satisfied with her pizza.";
}