#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 10e5;
        int max_profit = 0;
        for(int i=0;i<prices.size();i++){
            max_profit = max(max_profit,prices[i]-min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};