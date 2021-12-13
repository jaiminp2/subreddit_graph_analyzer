#include "../include/graph.h"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
using std::pair;
using std::vector;
using std::priority_queue;
using std::greater;
using std::numeric_limits;
using std::unordered_map;
using std::sort;

DirectedGraph::DirectedGraph(vector<Post> posts) {
    for (Post post : posts) {
        Edge newEdge(post);
        if (adjList.find(newEdge.getSource()) == adjList.end()) {
            adjList.insert(std::pair<string, list<Edge>>(newEdge.getSource(), 
                list<Edge>()));
            adjList[newEdge.getSource()].push_back(newEdge);
            
        } else {
            adjList[newEdge.getSource()].push_back(newEdge);
        }
        if (adjList.find(newEdge.getDestination()) == adjList.end()) {
            adjList.insert(std::pair<string, list<Edge>>(newEdge.getDestination(), 
                list<Edge>()));
        }
    }
}

bool DirectedGraph::VertexExists(string name) const {
    return adjList.find(name) != adjList.end(); 
}

list<Edge> DirectedGraph::GetEdges(string name) {
   return adjList[name];
}

int DirectedGraph::ShortestPath(string start, string end, string weightType) {

    int max = numeric_limits<int>::max();

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> queue;
    unordered_map<string, int> distances;

    for (auto const& node : adjList) {
        if (node.first == start) {
            distances[node.first] = 0;
        } else {
            distances[node.first] = max;
        }
    }
    queue.push(make_pair(0, start));

    while (!queue.empty()) {
        string u = queue.top().second;
        queue.pop();

        for (Edge const& edge : adjList[u]) {
            string v = edge.getDestination();
            int weight = edge.getWeight(weightType);

            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                queue.push(make_pair(distances[v], v));
            }
            if (v == end) {
                return distances[v];
            }
        }
    }
    // if end is not found
    return -1;

}

bool DirectedGraph::CycleHelper(string original, string query, unordered_map<string, bool> visited) {
    if (visited[query] == false) {
        visited[query] = true;

        list<Edge>::iterator it;
        for (it = adjList[query].begin(); it != adjList[query].end(); ++it) {
            string next = (*it).getDestination();
            if (next == original) {
                return true;
            }
            if (!visited[next] && CycleHelper(original, next, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool DirectedGraph::NodeHasCycle(string original) {
    unordered_map<string, bool> visited;

    for (auto const& node : adjList) {
        visited[node.first] = false;
    }

    return CycleHelper(original, original, visited);
}