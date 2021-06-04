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

    int maxSize, moveCount;
    cin >> maxSize >> moveCount;

    vector<int> moves(moveCount);
    for (int &move : moves)
        cin >> move;

    string res(maxSize + 1, 'L');
    for (int size = 1; size <= maxSize; size++)
        for (int move : moves)
            if (size >= move && res[size - move] == 'L')
                res[size] = 'W';
    
    cout << res.substr(1);
}