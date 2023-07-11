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

    char c;
    cin >> c;

    string letters = "qwertyuiopasdfghjklzxcvbnmq";
    cout << letters[letters.find(c) + 1];
}