class Solution {
public:
    int maxHeight(vector<vector<int>> &boxes) {
        for (vector<int> &box : boxes)
            sort(box.begin(), box.end());
        
        sort(boxes.begin(), boxes.end(), [](auto &a, auto &b) {
            return a[0] * a[1] * a[2] < b[0] * b[1] * b[2];
        });
        
        vector<int> res(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            res[i] = boxes[i][2];
            for (int j = 0; j < i; j++)
                if (boxes[j][0] <= boxes[i][0] && boxes[j][1] <= boxes[i][1] && boxes[j][2] <= boxes[i][2])
                    res[i] = max(res[i], res[j] + boxes[i][2]);
        }
        
        return *max_element(res.begin(), res.end());
    }
};