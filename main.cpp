#include <iostream>

#include "include/graph.h"
#include "include/graphTraversal.h"

#include <vector>

int main(int argc, const char *argv[])
{
	std::vector<Post> posts = inputFile("data/soc-redditHyperlinks-body.tsv", 2000000);
	DirectedGraph graph = DirectedGraph(posts);
	std::string first_arg = argv[1];
	if (first_arg.compare("shortestpath") == 0)
	{
		if (graph.VertexExists(std::string(argv[2])) && graph.VertexExists(std::string(argv[3])))
		{
			if (argc == 5)
			{
				int dist = graph.ShortestPath(argv[2], argv[3], argv[4]);
				std::cout << "The shortest path from " << argv[2] << " to " << argv[3] << " considering weights as " << argv[4] << " has distance " << dist << " ." << std::endl;
			}
		}
		else if (!graph.VertexExists(argv[2]))
		{
			std::cout << "Wrong input : " << argv[2] << std::endl;
		}
		if (!graph.VertexExists(argv[3]))
		{
			std::cout << "Wrong input : " << argv[3] << std::endl;
		}
	}
	
	else if (first_arg.compare("bfs") == 0)
	{
		if (graph.VertexExists(std::string(argv[2])) && graph.VertexExists(std::string(argv[3])))
		{
			if (argc == 4)
			{
				GraphTraversal gT(&graph, std::string(argv[2]));
				for (GraphTraversal::Iterator it = gT.begin();; ++it)
				{
					std::cout << "Current Node : " << *it << std::endl;
					std::string s = *it;
					if (s.compare(std::string(argv[3])) == 0)
					{
						std::cout << "Reached Target Subreddit!" << std::endl;
						break;
					}
				}
			}
		}
	}

	else if (first_arg.compare("cycledetector")==0)
	{
		if (argc != 3)
		{
			std::cout << "Invalid Number of input arguments" << std::endl;
		}
		else
		{
			if (graph.VertexExists(std::string(argv[2])))
			{
			if(graph.NodeHasCycle(std::string(argv[2]))){
					std::cout << "The graph has a cycle involving node " << argv[2] << std::endl;
			}
			else{
					std::cout << "The graph does not have a cycle involving node " << argv[2] << std::endl;
				}
			}
			else
			{
			std::cout << "Invalid start subreddit" << std::endl;
			}
		}	
	}
return 1;
}

