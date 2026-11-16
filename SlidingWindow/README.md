# SlidingWindow

[All topics](../README.md)

Fixed-size windows; variable-size constraints; monotonic deque; non-overlapping windows.

A fixed window updates an aggregate as its endpoints advance together. A variable window changes its width to maintain a validity condition. Streak accumulation and prefix-minimum scans are indexed under ArraysAndHashing.

## FixedSizeWindows (8)

Maintain rolling sums, counts, or bounded membership for a fixed-size window; includes circular indexing and incremental benefit calculations.

- [1052_GrumpyBookstoreOwner.cpp](FixedSizeWindows/1052_GrumpyBookstoreOwner.cpp)
- [1343_NumberOfSubarraysOfSizeKAndAverageGreaterThanOrEqualToThreshold.cpp](FixedSizeWindows/1343_NumberOfSubarraysOfSizeKAndAverageGreaterThanOrEqualToThreshold.cpp)
- [1456_MaximumNumberOfVowelsInASubstringOfGivenLength.cpp](FixedSizeWindows/1456_MaximumNumberOfVowelsInASubstringOfGivenLength.cpp)
- [2090_KRadiusSubarrayAverages.cpp](FixedSizeWindows/2090_KRadiusSubarrayAverages.cpp)
- [2134_MinimumSwapsToGroupAllOnesTogetherII.cpp](FixedSizeWindows/2134_MinimumSwapsToGroupAllOnesTogetherII.cpp)
- [219_ContainsDuplicateII.cpp](FixedSizeWindows/219_ContainsDuplicateII.cpp)
- [2379_MinimumRecolorsToGetKConsecutiveBlackBlocks.cpp](FixedSizeWindows/2379_MinimumRecolorsToGetKConsecutiveBlackBlocks.cpp)
- [643_MaximumAverageSubarrayI.cpp](FixedSizeWindows/643_MaximumAverageSubarrayI.cpp)

## VariableSizeConstraints (4)

Expand right and shrink left to restore a monotone validity condition; optimize a valid window or count valid suffixes.

- [1004_MaxConsecutiveOnesIII.cpp](VariableSizeConstraints/1004_MaxConsecutiveOnesIII.cpp)
- [2302_CountSubarraysWithScoreLessThanK.cpp](VariableSizeConstraints/2302_CountSubarraysWithScoreLessThanK.cpp)
- [3_LongestSubstringWithoutRepeatingCharacters.cpp](VariableSizeConstraints/3_LongestSubstringWithoutRepeatingCharacters.cpp)
- [424_LongestRepeatingCharacterReplacement.cpp](VariableSizeConstraints/424_LongestRepeatingCharacterReplacement.cpp)

## MonotonicDeque (1)

Keep only undominated candidate indices while evicting expired indices to report each window extremum.

- [SlidingWindowMinimum.cpp](MonotonicDeque/SlidingWindowMinimum.cpp)

## NonOverlappingWindows (1)

Combine rolling window sums with best completed choices for one, two, then three disjoint windows.

- [689_MaximumSumOf3NonOverlappingSubarrays.cpp](NonOverlappingWindows/689_MaximumSumOf3NonOverlappingSubarrays.cpp)

