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

    int abc, ac, ab;
    cin >> abc >> ac >> ab;

    int a = ab + ac - abc;
    int b = ab - a;
    int c = ac - a;

    cout << a << " " << b << " " << c;
}