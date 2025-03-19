#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getTime() {
    int a, b, c;
    cin >> a >> b >> c;

    return a + b * c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = getTime();
    int t2 = getTime();

    if (t1 <= t2)
        cout << "1 " << t1;
    else
        cout << "2 " << t2;
}