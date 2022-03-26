#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int n) {
    cout << n << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int n = 1; n < 97; n += n % 3 == 2 ? 1 : 2)
        n = ask(n);

    cout << "99\n";
    cout.flush();
}