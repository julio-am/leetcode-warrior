class Solution {
public:

    long long timeSpent(vector<int>& piles, double speed) {
        long long result = 0;
        for (auto pile : piles) {
            result += ceil(pile / speed); // needs speed to be double for ceil to work
        }
        return result;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN, result = r; 
        for (auto pile : piles) {
            r = max(r, pile);
        }

        while (l <= r) {
            int speed = l + (r-l)/2;

            long long time = timeSpent(piles, speed);

            // he's too fast
            if (time <= h) {
                result = speed;
                r = speed-1;
            } 

            else l = speed+1;
        }

        return result;
    }
};
