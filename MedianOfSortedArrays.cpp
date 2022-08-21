#include<climits>
#include<vector>
class MedianOfSortedArrays {
public:
	double getMedian(std::vector<int> a, std::vector<int> b)
	{
		// first array should be smaller
		// if not swap
		if(a.size() > b.size())
		{
			a.swap(b);
		}
		// size of a, b - n, m
		int n = a.size();
		int m = b.size();

		// two medians
		double m1, m2;
		// initialize binary search range
		int lo = 0, hi = n, mid;
		// do binary search
		while(lo <= hi)
		{
			// calculate mid. mid is no of 
			// elements selected from a - x
			mid = (lo + hi) / 2;
			// partition for second array
			int y = (n + m + 1) / 2 - mid; 
			// biggest element in left part of A
			int maxLeftA = (mid > 0) ? a[mid - 1] : INT_MIN;
			// smallest element in right part of A
			int minRightA = (mid < n) ? a[mid] : INT_MAX;
			// biggest element in left part of B
			int maxLeftB = (y > 0) ? b[y - 1] : INT_MIN;
			// smallest element in right part of B
			int minRightB = (y < n) ? b[y] : INT_MAX;
			//check if its right partition for median
			if(maxLeftA <= minRightB && minRightA >= maxLeftB)
			{
				// if even size
				if((n + m) % 2 == 0)
				{
					m1 = std::max(maxLeftA, maxLeftB);
					m2 = std::min(minRightA, minRightB);
				}
				// if odd size 
				else
				{
					// either return directly or make m1 equals m2 so that average is same
					m1 = m2 = std::max(maxLeftA, maxLeftB);
				}
				break;
			}
			// x should be less
			else if(maxLeftA > minRightB)
				hi = mid - 1;
			// x should be more
			else
				lo = mid + 1;
		}
		// return average of two medians
		return (m1 + m2) / 2;
	}
};