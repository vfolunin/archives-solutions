class StockPrice {
    map<int, int> priceAt;
    multiset<int> prices;
    
public:    
    void update(int time, int price) {
        if (priceAt.count(time))
            prices.erase(prices.find(priceAt[time]));
        priceAt[time] = price;
        prices.insert(price);
    }
    
    int current() {
        return prev(priceAt.end())->second;
    }
    
    int minimum() {
        return *prices.begin();
    }
    
    int maximum() {
        return *prev(prices.end());
    }
};