/**************************
 * Lab 3: exercise 3      *
 **************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

int main() {
	// läsa in fil i vector av strings

	std::string word; 
	std::map<std::string, std::set<std::string>> anagrams; 

	std::ifstream readFile("C:/Users/alars/Documents/TNG033/lab3/code/uppgift3.txt");
	std::ofstream writeFile("C:/Users/alars/Documents/TNG033/lab3/code/test.txt"); 
	
	if (readFile.is_open()) {
		while (readFile >> word) {
			std::string subject = word;
			std::sort(subject.begin(), subject.end());
			anagrams[subject].insert(word);
		}
		readFile.close();
	}
	else std::cout << "Could not open file!! nononono"; 

	writeFile << "-- ANAGRAMS --" << std::endl; 
	for (const auto& a : anagrams) {
		for (std::string s : a.second) {
			if (a.second.size() > 1) writeFile << s << " "; 
		}
		if (a.second.size() > 1) writeFile << " --> " << a.second.size() << " words.\n";
	}
	writeFile.close(); 
}

