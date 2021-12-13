#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::string;
using std::vector;
using std::stoi;
using std::stod;
using std::ifstream;
using std::getline;
using std::stringstream;

struct Post {
	string source;
	string target;
	string id;
	string timestamp;
	int linkSentiment;
	int numChars; // 0
	int numWords; // 7
	int numUniqueWords; //8
	double avgWordLen; // 10
	int numSentences; // 13
	double readability; // 17
	double positiveSentiment; // 18
	double negativeSentiment; // 19
	double compoundSentiment; // 20
};

/** 
 * Reads a file into a vector of posts
 * @param filename The file to read from 
 * @return a vector containing filename's contents
 */
vector<Post> inputFile(const string & filename, int postLimit);

