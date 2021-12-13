#include "../catch/catch.hpp"
#include "../include/graph.h"
#include "../include/graphTraversal.h"

TEST_CASE("BFS Iterator") {
	std::vector<Post> posts = inputFile("data/data_subset.tsv", 15);	
	DirectedGraph graph(posts);
	GraphTraversal gT(&graph,"denverbroncos");
	std::vector<std::string> vec{"denverbroncos","seahawks","mariners","baseball","letsgofish","braves","cardinals","nationals","collegebasketball"};

	SECTION("Traverses in correct order") {
		GraphTraversal::Iterator it = gT.begin();
		REQUIRE(*it == vec[0]);
		++it;
		REQUIRE(*it == vec[1]);
		++it;
		REQUIRE(*it == vec[2]);
		++it;
		REQUIRE(*it == vec[3]);
		++it;
		REQUIRE(*it == vec[4]);
		++it;
		REQUIRE(*it == vec[5]);
		++it;
		REQUIRE(*it == vec[6]);
		++it;
		REQUIRE(*it == vec[7]);
		++it;
		REQUIRE(*it == vec[8]);
	}
}