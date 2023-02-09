class Solution {
public:
    vector<int> timeTaken(vector<int> &time, vector<int> &fromRight) {
        queue<int> left, right;
        vector<int> res(time.size());
        enum { NONE, LEFT, RIGHT } last = NONE;

        for (int t = 0, i = 0; i < time.size() || !left.empty() || !right.empty(); t++) {
            for ( ; i < time.size() && t == time[i]; i++) {
                if (fromRight[i])
                    right.push(i);
                else
                    left.push(i);
            }

            if (!left.empty() && !right.empty()) {
                if (last == LEFT) {
                    res[left.front()] = t;
                    left.pop();
                    last = LEFT;
                } else {
                    res[right.front()] = t;
                    right.pop();
                    last = RIGHT;
                }
            } else if (!left.empty()) {
                res[left.front()] = t;
                left.pop();
                last = LEFT;
            } else if (!right.empty()) {
                res[right.front()] = t;
                right.pop();
                last = RIGHT;
            } else {
                last = NONE;
            }
        }

        return res;
    }
};