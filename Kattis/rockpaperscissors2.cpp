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

    string a, b;
    cin >> a >> b;

    vector<string> moves = { "rock", "scissors", "paper" };
    int aMove = find(moves.begin(), moves.end(), a) - moves.begin();
    int bMove = find(moves.begin(), moves.end(), b) - moves.begin();

    if (aMove == bMove)
        cout << "Draw";
    else if ((aMove + 1) % moves.size() == bMove)
        cout << "Player 1";
    else
        cout << "Player 2";
}