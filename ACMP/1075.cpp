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

    vector<int> a(11);
    for (int &value : a)
        cin >> value;

    vector<int> b(11);
    for (int &value : b)
        cin >> value;
    
    int balance = 0;
    for (int i = 0; i < a.size(); i++)
        balance += (a[i] < b[i] ? 1 : -1);

    cout << (balance > 0 ? "First" : "Second");
}