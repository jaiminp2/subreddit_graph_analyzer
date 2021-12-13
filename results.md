# Overview
- We were able to create a graph based on edges represented by hyperlinks from one subreddit on Reddit to another. We were able to successfully implement all of the deliverables we proposed such as the BFS iterator, Dijkstra's algorithm and cycle detection. 
# Data Parsing
- For data parsing, we inputted from .tsv files with each column representing a post attribute. We stored each individual post in a struct and added them to a vector. Because the data files are significantly large and take some time to input, for testing, we decided to also include a parameter for specifying the number of posts to be inputed. To test these functionalities, we wrote tests that compare the first and last post objects to the expected ones both with a specified input limit and with the entire dataset. 
# Directed Graph Class
- The graph class can be created by passing in a list of post structs, and methods like Dijikstra's shortest path algorithm and cycle identification for a specific vertex are implemented within this class. We tested the graph class constructor by checking for the existence of certain vertices that would be created given a list of post structs parsed from our dataset.
# Edge Class
- An edge object is essentially a post struct received after parsing the data but translated to become a graph edge.
- The edge class has public accessor methods to retrieve the following:
  - Start Subreddit
  - Destination Subreddit
  - Edge Weight (based on an input query) 
# BFS iterator / GraphTraversal Class:
- For traversing the graph without weighting the edges, we used a Breadth First Search iterator. The Breadth First Search iterator takes in the starting subreddit as an input and will reach the end once all the nodes have been visited. 
- The iterator also has a function to measure how far the current node is from the starting node.
- The runtime of Breadth First Search using an adjacency list with n nodes and e edges is O(n + e).
# Dijikstra’s Shortest Path
- We used Dijikstra’s Shortest Path algorithm using the STL Priority Queue data structure to identify the shortest weighted path between two subreddits. Our ShortestPath method takes in three parameters: the start subreddit, the destination subreddit, and the weighting scheme that one wishes to use. Dijikstra’s algorithm only works without modification on positive/unsigned weights, so we only included those schemes that are strictly non-negative.
- The method returns the sum of the weights as an `int` of the shortest path between the start and destination nodes. 
- The options for weighting scheme are as follows:
  - Number of Characters 
  - Number of Words
  - Number of Unique Words
  - Number of Sentences
  - If no weight or an invalid weight is provided, the algorithm assumes equal weighting of 1 and runs as if the graph is unweighted
- Runtime Complexity: if there are n nodes in the graph, the priority queue can contain up to n elements. Each pop operation can take up to log(n) time using the std::priority_queue. Thus, the runtime of our shortest path algorithm is n * log(n) = O(nlogn).
# Cycle Detection Algorithm
- We created a Cycle Detection Algorithm to identify if one can iterate through our directed graph and return to a given subreddit. The method takes in one parameter, the subreddit that one wishes to identify a cycle on, and has a recursive helper method that takes in an unordered map of visited subreddits to check if we have returned to the original subreddit. 
- Since we use an adjacency list, our runtime is the same as the Depth First Search which our algorithm is based on. With n nodes and e edges, our cycle detection algorithm’s runtime is O(n + e). 
# Discoveries
- We discovered that the adjacency list was the best way to represent our graph since the space tradeoff of creating an adjacency matrix for every node was not worth the O(1) lookup time for an edge. Our dataset was also incredibly large at over 300 MB and it was not dense enough to warrant the use of an adjacency matrix.
