#pragma once

#include "edge.h"
#include "graph.h"


#include <unordered_map>
#include <list>
#include <queue>
using std::unordered_map;
using std::list;
using std::vector;

class GraphTraversal {
public:
	GraphTraversal(DirectedGraph* graph, std::string start_subreddit);
	class Iterator : std::iterator<std::forward_iterator_tag, std::string> {
	public:
		Iterator();
		Iterator(std::string start_subreddit, DirectedGraph* graph, GraphTraversal* traversal);

		Iterator & operator++();
		std::string operator*();
		bool operator!=(const GraphTraversal::Iterator &other);
		int getDistanceFromSource();

	private:
		std::string start_subreddit_;
		DirectedGraph* graph_;
		GraphTraversal* traversal_;
		bool isEnd;
		std::string current_subreddit_;
		int dist;
		std::unordered_map<std::string, int> visited_subreddits;
	};

	/**
	* The begining of an iterator
	* Virtual function. Derived class need to implement this
	*/
	Iterator begin();

	/**
	* The end of an iterator
	* Virtual function. Derived class need to implement this
	*/
	Iterator end();
private:
	std::queue<std::pair<Edge, int>> queue;
	std::string start_subreddit_;
	DirectedGraph* graph_;
};