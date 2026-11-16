# Trees

[All topics](../README.md)

Bottom-up summaries; top-down path state; levels/views; BST ordering; lowest common ancestor; structure comparison.

Bottom-up recursion returns the summary the parent needs; top-down recursion passes ancestor context to children. Adjacency-list tree aggregation is indexed under Graphs.

## BottomUpSubtreeSummaries (4)

Return a parent-needed height or optimization state; record a global answer or per-node result separately when required.

- [104_MaximumDepthOfBinaryTree.cpp](BottomUpSubtreeSummaries/104_MaximumDepthOfBinaryTree.cpp)
- [337_HouseRobberIII.cpp](BottomUpSubtreeSummaries/337_HouseRobberIII.cpp)
- [366_FindLeavesOfBinaryTree.cpp](BottomUpSubtreeSummaries/366_FindLeavesOfBinaryTree.cpp)
- [543_DiameterOfBinaryTree.cpp](BottomUpSubtreeSummaries/543_DiameterOfBinaryTree.cpp)

## TopDownPathState (3)

Pass ancestor-derived context such as depth, path digits, or the maximum value seen so far.

- [129_SumRootToLeafNumbers.cpp](TopDownPathState/129_SumRootToLeafNumbers.cpp)
- [1448_CountGoodNodesInBinaryTree.cpp](TopDownPathState/1448_CountGoodNodesInBinaryTree.cpp)
- [339_NestedListWeightSum.cpp](TopDownPathState/339_NestedListWeightSum.cpp)

## LevelOrderAndViews (4)

Preserve breadth-first order while grouping nodes by level or column, selecting a view, or connecting neighbors.

- [102_BinaryTreeLevelOrderTraversal.cpp](LevelOrderAndViews/102_BinaryTreeLevelOrderTraversal.cpp)
- [116_PopulatingNextRightPointersInEachNode.cpp](LevelOrderAndViews/116_PopulatingNextRightPointersInEachNode.cpp)
- [199_BinaryTreeRightSideView.cpp](LevelOrderAndViews/199_BinaryTreeRightSideView.cpp)
- [314_BinaryTreeVerticalOrderTraversal.cpp](LevelOrderAndViews/314_BinaryTreeVerticalOrderTraversal.cpp)

## BinarySearchTreeOrdering (2)

Use ordered value bounds or subtree pruning to validate or query a BST.

- [938_RangeSumOfBST.cpp](BinarySearchTreeOrdering/938_RangeSumOfBST.cpp)
- [98_ValidateBinarySearchTree.cpp](BinarySearchTreeOrdering/98_ValidateBinarySearchTree.cpp)

## LowestCommonAncestor (3)

Locate shared ancestry through subtree presence, BST ordering, or parent-pointer path alignment.

- [1650_LowestCommonAncestorOfABinaryTreeIII.cpp](LowestCommonAncestor/1650_LowestCommonAncestorOfABinaryTreeIII.cpp)
- [235_LowestCommonAncestorOfABinarySearchTree.cpp](LowestCommonAncestor/235_LowestCommonAncestorOfABinarySearchTree.cpp)
- [236_LowestCommonAncestorOfABinaryTree.cpp](LowestCommonAncestor/236_LowestCommonAncestorOfABinaryTree.cpp)

## StructureComparison (2)

Recursively compare matching nodes and child structures.

- [100_SameTree.cpp](StructureComparison/100_SameTree.cpp)
- [572_SubtreeOfAnotherTree.cpp](StructureComparison/572_SubtreeOfAnotherTree.cpp)

## Other patterns and notes

- [Notes_SegmentTrees.md](Notes_SegmentTrees.md)

