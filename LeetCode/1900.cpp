class Solution {
    void rec(int totalCount, int leftCount, int rightCount, int round, int &minRound, int &maxRound) {
        if (leftCount == rightCount) {
            minRound = min(minRound, round);
            maxRound = max(maxRound, round);
            return;
        }
        
        if (leftCount > rightCount) {
            rec(totalCount, rightCount, leftCount, round, minRound, maxRound);
            return;
        }
        
        int nextTotalCount = (totalCount + 1) / 2;
        int totalLoseCount = totalCount / 2;
        
        for (int nextLeftCount = 0; nextLeftCount <= leftCount; nextLeftCount++) {
            int leftLoseCount = leftCount - nextLeftCount;
            int midRightLoseCount = totalLoseCount - leftLoseCount;

            int minNextRightCount = max(leftLoseCount, rightCount - midRightLoseCount);
            int maxNextRightCount = min(rightCount - nextLeftCount - 1, nextTotalCount - nextLeftCount - 2);
            
            for (int nextRightCount = minNextRightCount; nextRightCount <= maxNextRightCount; nextRightCount++)
                rec(nextTotalCount, nextLeftCount, nextRightCount, round + 1, minRound, maxRound);
        }
    }
    
public:
    vector<int> earliestAndLatest(int totalCount, int a, int b) {
        int minRound = 1e9, maxRound = -1e9;
        rec(totalCount, a - 1, totalCount - b, 1, minRound, maxRound);
        return { minRound, maxRound };
    }
};