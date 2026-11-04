// Alexa is given n piles of equal or unequal heights. In one step, Alexa can remove any number of boxes from the pile which has the maximum height and try to make it equal to the one which is just lower than the maximum height of the stack. Determine the minimum number of steps required to make all of the piles equal in height.

// Example 1:

// Input: piles = [5, 2, 1]
// Output: 3
// Explanation:
// Step 1: reducing 5 -> 2 [2, 2, 1]
// Step 2: reducing 2 -> 1 [2, 1, 1]
// Step 3: reducing 2 -> 1 [1, 1, 1]
// So final number of steps required is 3.

int minStepsToEqualHeight(vector<int>& piles) {
    if (piles.size() < 2) return 0;
    
    sort(piles.begin(), piles.end());
    
    int result = 0;
    int stepsNeeded = 0;
    
    for (int i = 1; i < piles.size(); ++i) {
        if (piles[i] != piles[i-1]) {
            stepsNeeded+=1;
        }
        result += stepsNeeded;
    }
    return result;
}

int main() {
    vector<int> piles = {};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles.push_back(1);
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles.push_back(0);
    std::cout << minStepsToEqualHeight(piles) << std::endl;
        
    piles = {5,5,5,5};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles = {5,5,5,6};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles = {1,2,3,4};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles = {3,1,2,4};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
    
    piles = {3,1,INT_MAX,4};
    std::cout << minStepsToEqualHeight(piles) << std::endl;

    piles = {3,1,INT_MAX, 4, 4};
    std::cout << minStepsToEqualHeight(piles) << std::endl;
}