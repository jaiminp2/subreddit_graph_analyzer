#include "readFromFile.hpp"

vector<Post> inputFile(const string & filename, int postLimit){
	ifstream dataFile;
	dataFile.open(filename);

	string headers;
	getline(dataFile, headers);

	vector<Post> posts;

	int totalCount = 0;
	while(!dataFile.eof() && totalCount <= postLimit) {

	    string line;
	    getline( dataFile, line);
	    stringstream buffer(line);
	    string temp;

	    Post post;

	    int count = 0;
	    while(getline( buffer, temp, '\t')) {
	        if (count == 0){
	        	post.source = temp.c_str();
	        } else if (count == 1) {
	        	post.target = temp.c_str();
	        } else if (count == 2) {
	        	post.id = temp.c_str();
	        } else if (count == 3) {
	        	post.timestamp = temp.c_str();
	        } else if (count == 4) {
	        	post.linkSentiment = stoi(temp.c_str());
	        } else if (count == 5) {
        		string s = temp.c_str();
        	    int start = 0;
			    int end = s.find(",");
			    int secondCount = 0;

			    while (end != -1) {
			        string substr = s.substr(start, end - start);
			        if (secondCount == 0) {
			        	post.numChars = stoi(substr);
			        } else if (secondCount == 7) {
			        	post.numWords = stoi(substr);
			        } else if (secondCount == 8) {
			        	post.numUniqueWords = stoi(substr);
			        } else if (secondCount == 10) {
			        	post.avgWordLen = stod(substr);
			        } else if (secondCount == 13) {
			        	post.numSentences = stoi(substr);
			        } else if (secondCount == 17) {
			        	post.readability = stod(substr);
			        } else if (secondCount == 18) {
			        	post.positiveSentiment = stod(substr);
			        } else if (secondCount == 19) {
			        	post.negativeSentiment = stod(substr);
			        } else if (secondCount == 20) {
			        	post.compoundSentiment = stod(substr);
			        }
			        start = end + 1;
			        end = s.find(",", start);
			        secondCount ++;
			    }
	        }
	    	count ++;    
	    }
	    posts.push_back(post);
	    totalCount ++;
	}
	posts.pop_back();

	return posts;
}