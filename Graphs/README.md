# Graphs

[All topics](../README.md)

Reachability/traversal; grid flood fill; multi-source BFS; directed edges/dependencies; adjacency-list subtree aggregation; shortest paths.

Flood fill groups BFS and DFS implementations of connected-component problems. Multi-source BFS starts from all sources at once to compute distance or elapsed time.

## ReachabilityAndTraversal (5)

Visit each reachable vertex or state once; aggregate values, find a target, or memoize cloned nodes.

- [1306_JumpGameIII.cpp](ReachabilityAndTraversal/1306_JumpGameIII.cpp)
- [133_CloneGraph.cpp](ReachabilityAndTraversal/133_CloneGraph.cpp)
- [1971_FindIfPathExistsInGraph.cpp](ReachabilityAndTraversal/1971_FindIfPathExistsInGraph.cpp)
- [690_EmployeeImportance.cpp](ReachabilityAndTraversal/690_EmployeeImportance.cpp)
- [841_KeysAndRooms.cpp](ReachabilityAndTraversal/841_KeysAndRooms.cpp)

## GridFloodFill (3)

Treat neighboring grid cells as edges; find components, aggregate area, or mark cells connected to a boundary.

- [130_SurroundedRegions.cpp](GridFloodFill/130_SurroundedRegions.cpp)
- [200_NumberOfIslands.cpp](GridFloodFill/200_NumberOfIslands.cpp)
- [695_MaxAreaOfIsland.cpp](GridFloodFill/695_MaxAreaOfIsland.cpp)

## MultiSourceBFS (2)

Seed the queue with all sources; each layer represents one unit of distance or elapsed time.

- [286_WallsAndGates.cpp](MultiSourceBFS/286_WallsAndGates.cpp)
- [994_RottingOranges.cpp](MultiSourceBFS/994_RottingOranges.cpp)

## DirectedEdgesAndDependencies (3)

Reason about incoming edges, directed-edge aggregates, and dependency cycles. Course Schedule uses a DFS recursion stack.

- [1557_MinimumNumberOfVerticesToReachAllNodes.cpp](DirectedEdgesAndDependencies/1557_MinimumNumberOfVerticesToReachAllNodes.cpp)
- [207_CourseSchedule.cpp](DirectedEdgesAndDependencies/207_CourseSchedule.cpp)
- [2374_NodeWithHighestEdgeScore.cpp](DirectedEdgesAndDependencies/2374_NodeWithHighestEdgeScore.cpp)

## AdjacencyListSubtreeAggregation (3)

Root an undirected tree with a parent argument; return subtree summaries and record node or global answers.

- [1519_NumberOfNodesInTheSubTreeWithTheSameLabel.cpp](AdjacencyListSubtreeAggregation/1519_NumberOfNodesInTheSubTreeWithTheSameLabel.cpp)
- [2477_MinimumFuelCostToReportToTheCapital.cpp](AdjacencyListSubtreeAggregation/2477_MinimumFuelCostToReportToTheCapital.cpp)
- [3249_CountTheNumberOfGoodNodes.cpp](AdjacencyListSubtreeAggregation/3249_CountTheNumberOfGoodNodes.cpp)

## ShortestPaths (1)

Process tentative distances in priority order for weighted shortest paths.

- [Dijkstra.cpp](ShortestPaths/Dijkstra.cpp)

