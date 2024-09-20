//There are n gas stations along a circular route. You are given two integer arrays gas and cost where:

//gas[i] is the amount of gas at the ith station.
//cost[i] is the amount of gas needed to travel from the ith station to the (i + 1)th station. (The last station is connected to the first station)
//You have a car that can store an unlimited amount of gas, but you begin the journey with an empty tank at one of the gas stations.

//Return the starting gas station's index such that you can travel around the circuit once in the clockwise direction. If it's impossible, then return -1.

//It's guaranteed that at most one solution exists.
  
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int totalgas = 0;
        int result = 0;
        for (int i = 0; i < gas.size(); ++i){ 
            totalgas += (gas[i] - cost[i]);
    
            // find the first gas station such that we don't run out of gas on the way.
            // Because we know that the sum of gas is >= the sum of cost, we know
            // we will always have enough to complete a circle from that point.

            // we can't just return the first non-negative total due to the circular
            // nature of this problem. We might return pos 0 when the true answer
            // was pos nums.size()-1 etc. The answer will alwasy be the first station
            // after a series of negative or zero numbers.
            if (totalgas < 0) {
                totalgas = 0;
                result = i+1;
            }
        }

        return result;        
    }
};
