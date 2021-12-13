#include "../catch/catch.hpp"
#include "../include/graph.h"



TEST_CASE("file_inputs:data_limit") {
	std::vector<Post> posts = inputFile("data/soc-redditHyperlinks-body.tsv", 10);
	REQUIRE(posts.size() == 10);
	REQUIRE(posts[0].id == "1u4nrps");
	REQUIRE(posts[posts.size() - 1].id == "1u5ccus");
	REQUIRE(posts[posts.size() - 1].target == "corejerk");
}

TEST_CASE("file_inputs:full_dataset") {
	std::vector<Post> posts = inputFile("data/soc-redditHyperlinks-body.tsv", 2000000);
	REQUIRE(posts.size() == 286561);
	REQUIRE(posts[0].id == "1u4nrps");
	REQUIRE(posts[posts.size() - 1].id == "68ipeos");
}

TEST_CASE("Graph Constructor") {
	std::vector<Post> posts = inputFile("data/soc-redditHyperlinks-body.tsv", 10);
	DirectedGraph graph(posts);
	SECTION("Vertices for first edge exist") {
		REQUIRE(graph.VertexExists("leagueoflegends"));
		REQUIRE(graph.VertexExists("teamredditteams"));
	}

	SECTION("Vertices for edges coming out of same vertex") {
		REQUIRE(graph.VertexExists("posthardcore"));
		REQUIRE(graph.VertexExists("bestof2013"));
		REQUIRE(graph.VertexExists("corejerk"));
	}
}

TEST_CASE("Dijiksta's Shortest Path") {
	std::vector<Post> posts = inputFile("data/soc-redditHyperlinks-body.tsv", 25);
	DirectedGraph graph(posts);
	SECTION("Finds shortest path with no weight specified") {
		REQUIRE(graph.ShortestPath("dogemarket", "novacoin", "unweighted") == 2);
	}
	SECTION("Finds shortest path with number of words as weight parameter") {
		REQUIRE(graph.ShortestPath("dogemarket", "novacoin", "words") == 636);
	}
}

TEST_CASE("Cycle Detection") {
	std::vector<Post> posts = inputFile("data/cycle_data_subset.tsv", 4);
	DirectedGraph graph(posts);
	SECTION("Correctly identifies no cycle (false)") {
		REQUIRE(graph.NodeHasCycle("letsgofish") == false);
	}
	SECTION("Correctly identifies a cycle (true)") {
		REQUIRE(graph.NodeHasCycle("seahawks"));
	}
}