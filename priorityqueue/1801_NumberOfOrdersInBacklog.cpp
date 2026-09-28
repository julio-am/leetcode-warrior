class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>, 
            greater<pair<int,int>> 
        > sellOrders; // lowest price on top

        priority_queue<pair<int,int>> buyOrders; //biggest price on top


        for (auto order : orders) {
            int price = order[0];
            int amount = order[1];

            // buy order
            if (order[2] == 0) {
                while (!sellOrders.empty() && sellOrders.top().first <= price) {
                    auto [sellPrice, sellAmount] = sellOrders.top();
                    sellOrders.pop();

                    if (sellAmount > amount) {
                        sellOrders.push({sellPrice, sellAmount-amount});
                        amount = 0;
                        break;
                    }

                    else {
                        amount -= sellAmount;
                        continue;
                    }
                }

                if (amount > 0) buyOrders.push({price, amount});
            }

            // sell order
            else if (order[2] == 1) {
                while (!buyOrders.empty() && buyOrders.top().first >= price) {
                    auto [buyPrice, buyAmount] = buyOrders.top();
                    buyOrders.pop();

                    if (buyAmount > amount) {
                        buyOrders.push({buyPrice, buyAmount-amount});
                        amount = 0;
                        break;
                    }

                    else {
                        amount -= buyAmount;
                        continue;
                    }
                }

                if (amount > 0) sellOrders.push({price, amount});
            }
        }

        long long unsigned remaining = 0;
        while (!sellOrders.empty()) {
            remaining += sellOrders.top().second;
            sellOrders.pop();
        }

        while (!buyOrders.empty()) {
            remaining += buyOrders.top().second;
            buyOrders.pop();
        }

        return remaining % 1000000007;
    }
};
