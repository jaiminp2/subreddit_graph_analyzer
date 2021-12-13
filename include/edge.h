#pragma once

#include "../readFromFile.hpp"

#include <string>

using std::string;

class Edge {
  public:
	Edge(Post post);
    string getSource() const;
    string getDestination() const;

	/** Returns the value associated with the specified weight type for this Edge
	 * If the passed in weightType is invalid, the function returns 1, making the graph essentially unweighted
	 * @param weightType the desired weighting scheme
	 * @return int representing the value of the weight 
	 */
	int getWeight(string weightType) const;

  private:
    string src_;
    string dest_;
    string id_;
	string timestamp_;
	int linkSentiment_;
	int numChars_;
	int numWords_;
	int numUniqueWords_;
	double avgWordLen_;
	int numSentences_;
	double readability_;
	double positiveSentiment_;
	double negativeSentiment_;
	double compoundSentiment_;
};