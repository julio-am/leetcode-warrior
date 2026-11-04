# LeetCode Warrior

Solutions grouped by reusable algorithms, state invariants, and solving strategies. Each numbered problem has one file; different implementations of that problem are collected in comment-separated sections within the file.

## Pattern index

| Topic | Files | Pattern groups |
| --- | ---: | --- |
| [ArraysAndHashing](ArraysAndHashing/README.md) | 30 | Membership/complements; frequency counting/voting; canonical keys; prefix/suffix aggregates; adjacent streaks; construction/mutation; ordering scans. |
| [SlidingWindow](SlidingWindow/README.md) | 14 | Fixed-size windows; variable-size constraints; monotonic deque; non-overlapping windows. |
| [TwoPointers](TwoPointers/README.md) | 11 | Opposing pointers; sorted pair search; synchronized scans and merging. |
| [Graphs](Graphs/README.md) | 17 | Reachability/traversal; grid flood fill; multi-source BFS; directed edges/dependencies; adjacency-list subtree aggregation; shortest paths. |
| [Trees](Trees/README.md) | 19 | Bottom-up summaries; top-down path state; levels/views; BST ordering; lowest common ancestor; structure comparison. |
| [BinarySearch](BinarySearch/README.md) | 13 | Sorted lookup/bounds; answer-space feasibility; rotated arrays. Peak and partition searches stay at the topic root. |
| [Backtracking](Backtracking/README.md) | 11 | Subsets/combinations; permutations; constrained generation; grid path search. |
| [Stacks](Stacks/README.md) | 10 | Parentheses validation/repair; expression evaluation; monotonic stack; sequence reduction. MinStack stays at the topic root. |
| [DataStructureDesign](DataStructureDesign/README.md) | 5 | TTL expiration; LRU recency; rate limiting; recent time windows; ordered stream candidates. Kept flat while this collection is small. |

Counts include solution files and existing notes; new README files are excluded.

## Smaller collections

These collections remain flat until more examples justify useful subdivisions.

| Topic | Files |
| --- | ---: |
| [1dDynamicProgramming](1dDynamicProgramming/) | 8 |
| [2dDynamicProgramming](2dDynamicProgramming/) | 1 |
| [Bits](Bits/) | 1 |
| [Greedy](Greedy/) | 10 |
| [Intervals](Intervals/) | 6 |
| [LinkedLists](LinkedLists/) | 4 |
| [Math](Math/) | 8 |
| [Sorting](Sorting/) | 1 |
| [Tries](Tries/) | 1 |
| [priorityqueue](priorityqueue/) | 5 |

Standalone snippets remain at the repository root.

## Choosing a home

- Prefer the main invariant: fixed or variable window, prefix aggregate, subtree summary, path context, monotone candidates, or a search predicate.
- Keep all approaches to the same numbered problem in one file. Cross-reference a related topic when an alternative approach spans families.
- Keep small collections flat; add a subcategory when it represents a useful recurring algorithm family.

## Existing practice sequences

| Pattern | Sequence |
| --- | --- |
| Fixed windows | [643](SlidingWindow/FixedSizeWindows/643_MaximumAverageSubarrayI.cpp) → [1343](SlidingWindow/FixedSizeWindows/1343_NumberOfSubarraysOfSizeKAndAverageGreaterThanOrEqualToThreshold.cpp) → [1456](SlidingWindow/FixedSizeWindows/1456_MaximumNumberOfVowelsInASubstringOfGivenLength.cpp) → [2090](SlidingWindow/FixedSizeWindows/2090_KRadiusSubarrayAverages.cpp) → [2134](SlidingWindow/FixedSizeWindows/2134_MinimumSwapsToGroupAllOnesTogetherII.cpp) |
| Adjacent runs and counting | [3105](ArraysAndHashing/StreaksAndAdjacentRuns/3105_LongestStrictlyIncreasingOrDecreasingSubarray.cpp) → [3254](ArraysAndHashing/StreaksAndAdjacentRuns/3254_FindThePowerOfKSizeSubarraysI.cpp) → [2110](ArraysAndHashing/StreaksAndAdjacentRuns/2110_NumberOfSmoothDescentPeriodsOfAStock.cpp) → [413](ArraysAndHashing/StreaksAndAdjacentRuns/413_ArithmeticSlices.cpp) |
| Reachability to subtree summaries | [1971](Graphs/ReachabilityAndTraversal/1971_FindIfPathExistsInGraph.cpp) → [841](Graphs/ReachabilityAndTraversal/841_KeysAndRooms.cpp) → [3249](Graphs/AdjacencyListSubtreeAggregation/3249_CountTheNumberOfGoodNodes.cpp) → [2477](Graphs/AdjacencyListSubtreeAggregation/2477_MinimumFuelCostToReportToTheCapital.cpp) → [1519](Graphs/AdjacencyListSubtreeAggregation/1519_NumberOfNodesInTheSubTreeWithTheSameLabel.cpp) |
| Bottom-up tree returns | [104](Trees/BottomUpSubtreeSummaries/104_MaximumDepthOfBinaryTree.cpp) → [366](Trees/BottomUpSubtreeSummaries/366_FindLeavesOfBinaryTree.cpp) → [543](Trees/BottomUpSubtreeSummaries/543_DiameterOfBinaryTree.cpp) → [337](Trees/BottomUpSubtreeSummaries/337_HouseRobberIII.cpp) |
| Binary-search invariants | [704](BinarySearch/SortedLookup/704_BinarySearch.cpp) → [35](BinarySearch/SortedLookup/35_SearchInsertPosition.cpp) → [34](BinarySearch/SortedLookup/34_FindFirstAndLastPositionOfElementInSortedArray.cpp) → [875](BinarySearch/AnswerSpace/875_KokoEatingBananas.cpp) → [1011](BinarySearch/AnswerSpace/1011_CapacityToShipPackagesWithinDDays.cpp) |
| Expiration and recency | [1797](DataStructureDesign/1797_DesignAuthenticationManager.cpp) → [146](DataStructureDesign/146_LRUCache.cpp) |
