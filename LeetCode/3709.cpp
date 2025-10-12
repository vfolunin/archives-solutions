class ExamTracker {
    map<int, long long> pSums;
    long long pSum = 0;

public:    
    void record(int time, int score) {
        pSum += score;
        pSums[time] = pSum;
    }
    
    long long totalScore(int l, int r) {
        auto it = pSums.upper_bound(r);
        if (it == pSums.begin())
            return 0;

        long long res = prev(it)->second;

        it = pSums.lower_bound(l);
        if (it != pSums.begin())
            res -= prev(it)->second;
        
        return res;
    }
};