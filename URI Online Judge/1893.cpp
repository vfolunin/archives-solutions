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

    if (b <= 2)
        cout << "nova\n";
    else if (a <= b && b <= 96)
        cout << "crescente\n";
    else if (b >= 97)
        cout << "cheia\n";
    else if(a >= b && b >= 3)
        cout << "minguante\n";
}