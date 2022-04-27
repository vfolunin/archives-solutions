class Solution {
public:
    int finalValueAfterOperations(vector<string> &ops) {
        int value = 0;
        for (string &op : ops) {
            value += op[1] == '+';
            value -= op[1] == '-';
        }
        return value;
    }
};