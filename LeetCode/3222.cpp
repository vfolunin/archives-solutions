class Solution {
public:
    string losingPlayer(int k75, int k10) {
        int roundCount = min(k75, k10 / 4);
        return roundCount % 2 ? "Alice" : "Bob";
    }
};