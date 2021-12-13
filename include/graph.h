#pragma once

#include "edge.h"

#include <unordered_map>
#include <list>

using std::unordered_map;
using std::list;
using std::vector;

class DirectedGraph {
  public:
    DirectedGraph(vector<Post> posts);
    bool VertexExists(string name) const;
    int ShortestPath(string start, string end, string weightType);
    list<Edge> GetEdges(string name);
    bool NodeHasCycle(string original);
  
  private:
    unordered_map<string, list<Edge>> adjList;
    bool CycleHelper(string original, string query, unordered_map<string, bool> visited);
};