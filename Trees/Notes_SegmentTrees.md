# Segment trees

## Applications
* operations across a range of values in an array
* Supports: Update and Query in log(n) time
  * Ex: Sum across range
  * Supports updating values 

The root node represents the range of the entire array. 
As we go down the children, we break up the array into smaller portions of the root array.
Downside: When we updata an array, we have to update each node that contains the array value.

# How to build a Segment Tree
For each node, M (the split/middle) is the left + right rounded down. Base case is L = R 
Each node carries its own sum. Base Case carries the sum of its array index

  M = (L+R) / 2  
      (L, R)
  (L, M)   (M+1, R)


.            (0,5)
      (0,2)          (3,5)
   (0,1) (2,2)    (3,4) (5,5)
(0,0)(1,1)     (3,3)(4,4)







  
