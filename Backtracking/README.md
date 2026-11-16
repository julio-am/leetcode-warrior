# Backtracking

[All topics](../README.md)

Subsets/combinations; permutations; constrained generation; grid path search.

Grid search restores path-local visited state after exploring a branch. Flood fill marks a component permanently and is indexed under Graphs/GridFloodFill.

## SubsetsAndCombinations (6)

Choose or skip candidates while carrying a subset, a count, a target sum, or an aggregate; control reuse and duplicate branches.

- [1863_SumOfAllSubsetXORTotals.cpp](SubsetsAndCombinations/1863_SumOfAllSubsetXORTotals.cpp)
- [39_CombinationSum.cpp](SubsetsAndCombinations/39_CombinationSum.cpp)
- [40_CombinationSumII.cpp](SubsetsAndCombinations/40_CombinationSumII.cpp)
- [77_Combinations.cpp](SubsetsAndCombinations/77_Combinations.cpp)
- [78_Subsets.cpp](SubsetsAndCombinations/78_Subsets.cpp)
- [90_SubsetsII.cpp](SubsetsAndCombinations/90_SubsetsII.cpp)

## Permutations (2)

Choose the next element of an ordering, restoring swaps or availability state between branches.

- [46_Permutations.cpp](Permutations/46_Permutations.cpp)
- [47_PermutationsII.cpp](Permutations/47_PermutationsII.cpp)

## ConstrainedGeneration (2)

Build an output one position at a time using the valid choices at that position.

- [17_LetterCombinationsOfAPhoneNumber.cpp](ConstrainedGeneration/17_LetterCombinationsOfAPhoneNumber.cpp)
- [22_GenerateParentheses.cpp](ConstrainedGeneration/22_GenerateParentheses.cpp)

## GridPathSearch (1)

Explore a candidate path with path-local visited state that is restored when a branch fails.

- [79_WordSearch.cpp](GridPathSearch/79_WordSearch.cpp)

