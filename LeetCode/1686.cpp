class Solution {
public:
    int stoneGameVI(vector<int> &a, vector<int> &b) {
        vector<int> p(a.size());
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return a[i] + b[i] > a[j] + b[j];
        });
        
        vector<int> score(2);
        for (int i = 0; i < p.size(); i++)
            score[i % 2] += i % 2 ? b[p[i]] : a[p[i]];
        
        if (score[0] > score[1])
            return 1;
        else if (score[0] == score[1])
            return 0;
        else
            return -1;
    }
};