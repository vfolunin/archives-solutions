class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int sizeLimit, int labelLimit) {
        vector<int> p(values.size());
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int a, int b) {
            return values[a] > values[b];
        });
        
        int size = 0, res = 0;
        unordered_map<int, int> labelCount;
        for (int i = 0; i < p.size() && size < sizeLimit; i++) {
            if (labelCount[labels[p[i]]] < labelLimit) {
                size++;
                res += values[p[i]];
                labelCount[labels[p[i]]]++;
            }
        }
        
        return res;
    }
};