# ablamp2-varunrs2-vad4-jaiminp2

# Presentation

[Click Here](https://mediaspace.illinois.edu/media/t/1_281d1grt)

# Quick Start

Clone the repository, and `cd` into the appropriate folder. 

`cd ablamp2-varunrs2-vad4-jaiminp2`

## Dataset Downloading 

The unprocessed data sets of Reddit Hyperlinks can be downloaded in .tsv form [here (links in bodies of Reddit posts)](http://snap.stanford.edu/data/soc-redditHyperlinks-body.tsv) and [here (links in titles of Reddit posts)](http://snap.stanford.edu/data/soc-redditHyperlinks-title.tsv). 

## Importing the Dataset

Move/copy the downloaded .tsv files for the dataset into the `data` directory in the repository.

## Running the Code

### If on EWS, make sure to run `module load llvm/6.0.1`

To run the main method, run the following commands in the project root directory: 

`make` 

To run Dijkstra's shortest path algorithm between two subreddits (command line arguments required):

`./proj shortestpath subreddit1 subreddit2 weight_type`

Example:

`./proj shortestpath askreddit pics words`

To run BFS between two subreddits (command line arguments required):

`./proj bfs subreddit1 subreddit2`

Example:

`./proj bfs uiuc rutgers`

To run cycle detection for a given subreddit (command line arguments required):

`./proj cycledetector subreddit`

Example:

`./proj cycledetector askreddit`

# Running the Test Suite

To run the test suite, run the following commands in the project root directory:

`make test`

`./test`

The test suite contains tests for data parsing, the graph constructor, Dijkstra's shortest path algorithm, cycle identification for a specific vertex, and the BFS iterator.
