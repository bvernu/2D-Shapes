//mapset.cpp

#include <fstream>
//#include <set>
#include "SetList.h"
//#include <map>
#include "MapArray.h"
#include <iterator>

std::string to_lower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main(){
	std::ifstream stopwords_file{"stopwords.txt"};
    //std::set<std::string> stopwords;
    SetList<std::string> stopwords;
    std::transform(std::istream_iterator<std::string>(stopwords_file),
    			   std::istream_iterator<std::string>(),
                   std::inserter(stopwords, stopwords.end()),
                   to_lower);

    std::ifstream document{"sample_doc.txt"};
    //std::map<std::string, int> word_counts;
    MapArray<std::string, int> word_counts;
    std::for_each(std::istream_iterator<std::string>(document),
    			  std::istream_iterator<std::string>(),
                  [&](std::string word) {
                		word = to_lower(word);
                        if (stopwords.find(word) == stopwords.end()) {
                        	word_counts[word]++;
                        }
                    });

    std::ofstream output{"frequency.txt"};
    for (auto const& [word, count] : word_counts) {
    	output << word << ' ' << count << '\n';
    }
}


