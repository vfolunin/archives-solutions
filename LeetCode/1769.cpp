class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size());
        int lBalls = 0, rBalls = 0;
        
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                res[0] += i;
                rBalls++;
            }
        }
        lBalls += boxes[0] == '1';
        rBalls -= boxes[0] == '1';
        
        for (int i = 1; i < boxes.size(); i++) {
            res[i] = res[i - 1] - rBalls + lBalls;
            lBalls += boxes[i] == '1';
            rBalls -= boxes[i] == '1';
        }
        
        return res;
    }
};