#ifndef _MY_DIJKSTRA_H_
#define _MY_DIJKSTRA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <utility>
#include <algorithm> // my stdlib is borked! LOL 

typedef unsigned int NodeType;
typedef unsigned int WeightType;
typedef std::vector<std::vector<std::pair<NodeType, WeightType>>> GraphType; // graph as adjacent list

/*------------------------------------------------------------------------------
 ShortestPath_Dijkstra
  Find and print the shortest path from source to end using the Dijkstra's algorithm

 Vairables:
   - graph: the input graph
   - source: the source node
   - end: the target node
   - path_len: the the summation of weights of all edges in the shortest path
   - path: the shortest path represented as a list of nodes

------------------------------------------------------------------------------*/
void ShortestPath_Dijkstra(
    const GraphType &graph,
    const NodeType &source,
    const NodeType &end,
    WeightType &path_len,
    std::vector<NodeType> &path)
{
  /*------ CODE BEGINS ------*/
  std::priority_queue<
      std::pair<WeightType, NodeType>,
      std::vector<std::pair<WeightType, NodeType>>,
      std::greater<std::pair<WeightType, NodeType>>>
      pq;

  std::vector<WeightType> dist(graph.size(), UINT_MAX);
  std::vector<NodeType> prev(graph.size(), -1);

  // we use a PQ of pairs of (dist, id), so PQ will choose
  // by shortest distance then by id to match specification, ie. tiebreaker is by lower id
  pq.push(std::make_pair(0, source));
  dist[source] = 0;

  while (!pq.empty())
  {
    NodeType u = pq.top().second;
    pq.pop();

    if (u == end)
      break;

    for (const auto &adj : graph[u])
    {
      NodeType v = adj.first;
      WeightType weight = adj.second;

      if (dist[v] > dist[u] + weight)
      {
        dist[v] = dist[u] + weight;
        prev[v] = u;
        pq.push(std::make_pair(dist[v], v));
      }
    }
  }

  path_len = dist[end];
  if (path_len == UINT_MAX)
  {
    path.clear();
    return;
  }

  for (NodeType at = end; at != static_cast<NodeType>(-1); at = prev[at])
  {
    path.push_back(at);
  }

  std::reverse(path.begin(), path.end());
  /*------ CODE ENDS ------*/
}

#endif
