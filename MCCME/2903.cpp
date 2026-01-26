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

    vector<int> res(size + 1, 1);
    fill(res.begin() + 2, res.end(), 2);

    for (int i = 1; i < res.size(); i++)
        for (int j = i * 2; j < res.size(); j += i)
            res[j] += res[j] == res[i];

    cout << *max_element(res.begin() + 1, res.end()) << "\n";
    for (int i = 1; i < res.size(); i++)
        cout << res[i] << " ";
}