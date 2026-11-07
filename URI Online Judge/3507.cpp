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

    long long animals, legs;
    cin >> animals >> legs;

    long long tigers = (legs - animals * 2) / 2;
    long long geese = animals - tigers;

    cout << tigers << "\n" << geese << "\n";
}