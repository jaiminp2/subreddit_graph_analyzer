# CS 225 Data Structures
## Project Proposal (ablamp2-varunrs2-vad4-jaiminp2)

1. **Leading Question**
Given a starting and ending subreddit, we can find the shortest path that follows post links from the start to the end. Additionally, we will be able to filter the search by certain parameters (read about edge weighting in next section).

2. **Dataset Acquistion and Processing**
We propose using the [Stanford SNAP Reddit Hyperlink Network Dataset](http://snap.stanford.edu/data/soc-RedditHyperlinks.html). This dataset provides information about the post's source subreddit, target subreddit, sentiment towards target, and other miscellaneous properties about the post. This data is provided in a .tsv format, and we will cite this [reference](https://stackoverflow.com/questions/41645810/reading-a-specific-column-in-a-tsv-file) from Stack Overflow to load the data into an array format. For our graph structure, we propose that the nodes will be the subreddits and an edge will exist between two nodes if there exists a post that links the source sub to the target sub. There can exist multiple edges between two nodes, if there exist multiple posts that link between those two subreddits. We can assign the weight of an edge to be a variety of attributes about the post, including sentiment, character count, readability, and more.

3. **Graph Algorithms**
  For our graph traversal, we propose to implement a simple BFS using an iterator. We expect the input to our iterator constructor to be the starting subreddit. Every time we call operator++ on our implemented iterator, we expect it to update its internal position to a new subreddit, until there are no nodes left to traverse. 

  For one of our algorithms, we propose implementing Dijikstra's Algorithm. We expect the input to be the starting subreddit node and the destination subreddit node. We expect the output to be the shortest path between the start and destination that adheres to a filter.

  For our other algorithm, we propose to use a cycle identification algorithm to see if there exists a directed cycle from a starting subreddit back to itself using only valid edges. 

4. **Timeline**

  April 9 - sync to complete project proposal and team contract

  April 9 - submit project proposal and team contract

  April 12 - set up initial repository and Makefile

  April 15 - finish reading in data into array format and write simple tests to verify correctness

  April 19 - convert array format into graph format and pass simple tests

  April 22 - write BFS iterator and verify with tests

  April 29 - write Dijikstra's and verify with tests

  May 5 - write Cycle Identification and verify with tests

  May 7 - finish report

  May 9 - sync to record final presentation

  May 11 - finish editing presentation and submit
