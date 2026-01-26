#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> rotate(vector<int> &a) {
    vector<int> res(a.size());
    for (int value : a)
        for (int i = 0; i < value; i++)
            res[i]++;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, rotationCount;
    cin >> size >> rotationCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < 4 && rotationCount; i++, rotationCount--)
        a = rotate(a);

    rotationCount %= 4;

    for (int i = 0; i < rotationCount; i++)
        a = rotate(a);
    
    for (int value : a)
        cout << value << " ";
}