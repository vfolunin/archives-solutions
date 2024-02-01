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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;
    
    vector<long long> cost(a.size() + 1);
    cost[1] = a[0];
    for (int i = 2; i <= a.size(); i++)
        cost[i] = max(cost[i - 1], a[i - 1] + cost[i - 2]);
    
    cout << cost.back();
}