class Solution {
public:
    long long calculateScore(vector<string> &op, vector<int> &arg) {
        long long res = 0;
        for (int i = 0; 0 <= i && i < op.size(); ) {
            if (op[i] == "add") {
                res += arg[i];
                op[i] = "";
                i++;
            } else if (op[i] == "jump") {
                op[i] = "";
                i += arg[i];
            } else {
                break;
            }
        }
        return res;
    }
};