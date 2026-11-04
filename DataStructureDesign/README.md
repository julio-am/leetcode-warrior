# DataStructureDesign

[All topics](../README.md)

TTL expiration; LRU recency; rate limiting; recent time windows; ordered stream candidates. Kept flat while this collection is small.

| Problem | Reusable invariant |
| --- | --- |
| [1429_FirstUniqueNumber.cpp](1429_FirstUniqueNumber.cpp) | A queue preserves order while a frequency map identifies stale non-unique candidates. |
| [146_LRUCache.cpp](146_LRUCache.cpp) | A map and recency list agree on each cached key; access moves its node. |
| [1797_DesignAuthenticationManager.cpp](1797_DesignAuthenticationManager.cpp) | A map and expiration-ordered list agree on each live token; renewal moves its node. |
| [359_LoggerRateLimiter.cpp](359_LoggerRateLimiter.cpp) | Each message records its last permitted timestamp. |
| [933_NumberOfRecentCalls.cpp](933_NumberOfRecentCalls.cpp) | A chronological list retains calls within the active time window. |
