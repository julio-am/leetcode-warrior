Sample code
#include<vector>
class AllPermutations {
	private:
	    /*
	    takes an array, in and an index, ptr as input
		fixes all the terms before ptr
	    fixes all possible numbers at ptr by swapping each one of the terms ahead of ptr including ptr itself
	    calls permute(ptr+1,in)
	    swaps back to get the original in for next iteration of loop
	    */
	    void permute(std::vector<int> in, int startPosition) {
	        //end the recursion at ptr==n
	        if(ptr==in.size()) {
	            //store the permutation
	            res.push_back(in);
	            return;
	        }

	        //loop from ptr to last index of array
	        for(int i=startPosition; i<in.size(); ++i) {
	            //swap one of the possibilities

                //std::swap(in[startPos], in[i]);
	            int temp = in[startPosition];
	            in[startPosition] = in[i];
	            in[i] = temp;

                std::cout << in << std::endl;

	            //calling next recurrence
	            permute(in, startPosition+1);

	            //swapping back for next iteration of loop
	            temp = in[startPosition];
	            in[startPosition] = in[i];
	            in[i] = temp;
	        }
	        return;
	    }

	public:
	    //res to store all the permutation
	    std::vector<std::vector<int>> result;

	    /*
	    creates an array,in sorted ascending from 1 to n
	    calls permute from ptr=0 and array in
	    */
	    std::vector<std::vector<int>> getAll(int n) {
            std::vector<int> sortedArray;
	        for(int i=1; i<=n; ++i) {
	            sortedArray.push_back(i);
            }

        	permute(sortedArray, 0);
          return res;
	    }
};
