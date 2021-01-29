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

    set<long long> s = { 1 };

    for (int i = 0; i < 1499; i++) {
        long long x = *s.begin();
        s.erase(s.begin());
        s.insert(x * 2);
        s.insert(x * 3);
        s.insert(x * 5);
    }

    cout << "The 1500'th ugly number is " << *s.begin() << ".\n";
}