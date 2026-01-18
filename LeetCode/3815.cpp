class AuctionSystem {
    unordered_map<int, unordered_map<int, int>> bids;
    unordered_map<int, set<pair<int, int>>> sortedBids;

public:
    void addBid(int userId, int itemId, int bidAmount) {
        removeBid(userId, itemId);
        bids[itemId][userId] = bidAmount;
        sortedBids[itemId].insert({ bidAmount, userId });
    }
    
    void updateBid(int userId, int itemId, int bidAmount) {
        addBid(userId, itemId, bidAmount);
    }
    
    void removeBid(int userId, int itemId) {
        if (auto it = bids[itemId].find(userId); it != bids[itemId].end()) {
            sortedBids[itemId].erase({ it->second, it->first });
            bids[itemId].erase(it);
        }
    }
    
    int getHighestBidder(int itemId) {
        return sortedBids[itemId].empty() ? -1 : prev(sortedBids[itemId].end())->second;
    }
};