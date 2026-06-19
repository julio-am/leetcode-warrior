class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        // sort cars in descending order of position
        sort(cars.rbegin(), cars.rend());

        // Iterate backwards starting from the farthest forward car. 
        // Increment number of fleets if the current car won't catch up to the one in front. 
        auto frontCar = cars.front();
        int result = 1;

        for (auto car : cars) {
            double frontTime = (double)(target - frontCar.first) / frontCar.second;
            double backTime = (double)(target - car.first) / car.second;

            if (backTime > frontTime) {
                frontCar = car;
                ++result;
            }
        }

        return result;
    }
};
