# ArraysAndHashing

[All topics](../README.md)

Membership/complements; frequency counting/voting; canonical keys; prefix/suffix aggregates; adjacent streaks; construction/mutation; ordering scans.

The stored 215 implementation selects by value-range frequencies. Remove Duplicates and Move Zeroes use direct vector mutation. These groups describe the stored approaches.

## MembershipAndComplements (5)

Use set membership or a lookup of a transformed/complementary value; longest-consecutive starts only at sequence boundaries.

- [128_LongestConsecutiveSequence.cpp](MembershipAndComplements/128_LongestConsecutiveSequence.cpp)
- [1_TwoSum.cpp](MembershipAndComplements/1_TwoSum.cpp)
- [217_ContainsDuplicate.cpp](MembershipAndComplements/217_ContainsDuplicate.cpp)
- [2744_FindMaximumNumberOfStringPairs.cpp](MembershipAndComplements/2744_FindMaximumNumberOfStringPairs.cpp)
- [LargestPositiveAndNegativePairInRange.cpp](MembershipAndComplements/LargestPositiveAndNegativePairInRange.cpp)

## FrequencyCountingAndVoting (7)

Count occurrences with arrays, maps, or buckets; majority voting cancels unequal pairs without storing a histogram.

- [1647_MinimumDeletionsToMakeCharacterFrequenciesUnique.cpp](FrequencyCountingAndVoting/1647_MinimumDeletionsToMakeCharacterFrequenciesUnique.cpp)
- [169_MajorityElement.cpp](FrequencyCountingAndVoting/169_MajorityElement.cpp)
- [215_KthLargestElementInAnArray.cpp](FrequencyCountingAndVoting/215_KthLargestElementInAnArray.cpp)
- [242_ValidAnagram.cpp](FrequencyCountingAndVoting/242_ValidAnagram.cpp)
- [383_RansomNote.cpp](FrequencyCountingAndVoting/383_RansomNote.cpp)
- [409_LongestPalindrome.cpp](FrequencyCountingAndVoting/409_LongestPalindrome.cpp)
- [451_SortCharactersByFrequency.cpp](FrequencyCountingAndVoting/451_SortCharactersByFrequency.cpp)

## CanonicalKeysAndGrouping (2)

Build a canonical signature so equivalent inputs share a hash-map key.

- [249_GroupShiftedStrings.cpp](CanonicalKeysAndGrouping/249_GroupShiftedStrings.cpp)
- [49_GroupAnagrams.cpp](CanonicalKeysAndGrouping/49_GroupAnagrams.cpp)

## PrefixAndSuffixAggregates (6)

Keep an aggregate over everything before/after an index: prefix sums and frequency maps, prefix/suffix products, difference arrays, running minima, or suffix maxima.

- [121_BestTimeToBuyAndSellStock.cpp](PrefixAndSuffixAggregates/121_BestTimeToBuyAndSellStock.cpp)
- [1762_BuildingsWithAnOceanView.cpp](PrefixAndSuffixAggregates/1762_BuildingsWithAnOceanView.cpp)
- [238_ProductOfArrayExceptSelf.cpp](PrefixAndSuffixAggregates/238_ProductOfArrayExceptSelf.cpp)
- [370_RangeAddition.cpp](PrefixAndSuffixAggregates/370_RangeAddition.cpp)
- [560_SubarraySumEqualsK.cpp](PrefixAndSuffixAggregates/560_SubarraySumEqualsK.cpp)
- [974_SubarraySumsDivisibleByK.cpp](PrefixAndSuffixAggregates/974_SubarraySumsDivisibleByK.cpp)

## StreaksAndAdjacentRuns (4)

Maintain a summary of the contiguous run ending at the current index; reset when the adjacent relation breaks.

- [2110_NumberOfSmoothDescentPeriodsOfAStock.cpp](StreaksAndAdjacentRuns/2110_NumberOfSmoothDescentPeriodsOfAStock.cpp)
- [3105_LongestStrictlyIncreasingOrDecreasingSubarray.cpp](StreaksAndAdjacentRuns/3105_LongestStrictlyIncreasingOrDecreasingSubarray.cpp)
- [3254_FindThePowerOfKSizeSubarraysI.cpp](StreaksAndAdjacentRuns/3254_FindThePowerOfKSizeSubarraysI.cpp)
- [413_ArithmeticSlices.cpp](StreaksAndAdjacentRuns/413_ArithmeticSlices.cpp)

## ArrayConstructionAndMutation (4)

Construct rows/arrays or modify array contents directly. The stored RemoveDuplicates and MoveZeroes variants use vector::erase, not two-pointer compaction.

- [118_PascalsTriangle.cpp](ArrayConstructionAndMutation/118_PascalsTriangle.cpp)
- [1929_ConcatenationOfArray.cpp](ArrayConstructionAndMutation/1929_ConcatenationOfArray.cpp)
- [26_RemoveDuplicatesFromSortedArray.cpp](ArrayConstructionAndMutation/26_RemoveDuplicatesFromSortedArray.cpp)
- [283_MoveZeroes.cpp](ArrayConstructionAndMutation/283_MoveZeroes.cpp)

## OrderingAndSortedScans (2)

Scan an explicitly sorted order or compare neighboring words through a custom character-rank map.

- [1887_ReductionOperationsToMakeTheArrayElementsEqual.cpp](OrderingAndSortedScans/1887_ReductionOperationsToMakeTheArrayElementsEqual.cpp)
- [953_VerifyingAnAlienDictionary.cpp](OrderingAndSortedScans/953_VerifyingAnAlienDictionary.cpp)

