#include "../include/edge.h"

Edge::Edge(Post post) {
    src_ = post.source;
    dest_ = post.target;
    id_ = post.id;
	timestamp_ = post.timestamp;
	linkSentiment_ = post.linkSentiment;
	numChars_ = post.numChars;
	numWords_ = post.numWords;
	numUniqueWords_ = post.numUniqueWords;
	avgWordLen_ = post.avgWordLen;
	numSentences_ = post.numSentences;
	readability_ = post.readability;
	positiveSentiment_ = post.positiveSentiment;
	negativeSentiment_ = post.negativeSentiment;
	compoundSentiment_ = post.compoundSentiment;
}


string Edge::getSource() const {
    return src_;
}

string Edge::getDestination() const {
    return dest_;
}

int Edge::getWeight(string weightType) const {
	if (weightType == "chars" || weightType == "num chars") {
		return numChars_;
	} else if (weightType == "words" || weightType == "num words") {
		return numWords_;
	} else if (weightType == "unique words" || weightType == "num unique words") {
		return numUniqueWords_;
	} else if (weightType == "sentences" || weightType == "num sentences") {
		return numSentences_;
	} else {
		// if weight type is invalid, treat all weights as 1
		// making each edge equally weighted essentially makes the graph unweighted
		return 1;
	}
}