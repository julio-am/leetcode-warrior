//You are given an array of integers stones where stones[i] represents the weight of the ith stone.

//We want to run a simulation on the stones as follows:

//At each step we choose the two heaviest stones, with weight x and y and smash them togethers
//If x == y, both stones are destroyed
//If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
//Continue the simulation until there is no more than one stone remaining.

//Return the weight of the last remaining stone or return 0 if none remain.

class Solution {
private:
    int recursivelySmashStonesLol(priority_queue<int>& pq) {
        if (pq.size() == 0) return 0;
        if (pq.size() == 1) return pq.top();

        int stone1 = pq.top();
        pq.pop();

        int stone2 = pq.top();
        pq.pop();

        if (stone1 > stone2) {
            pq.push(stone1-stone2);
        } 

        return recursivelySmashStonesLol(pq);
    }

public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for (int stone : stones) pq.push(stone);

        return recursivelySmashStonesLol(pq);
    }
};
