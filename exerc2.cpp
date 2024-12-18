/****************************
 * Lab 3: exercise 2        *
 ****************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <algorithm>
#include <cmath>

double pythagoras(const std::pair<int, int>& P1, const std::pair<int, int>& P2) {
	double result = std::sqrt(pow((P1.first - P2.first), 2) + pow((P1.second - P2.second), 2));
	return result; 
}

int main() {

	std::ifstream readFile("C:/Users/alars/Documents/TNG033/lab3/code/points.txt"); 
	std::string pointString;
	std::vector<std::pair<int, int>> points; 

	if (readFile.is_open()) {
		auto f = [](const std::string& s) {
			std::pair<int, int> coords;
			char comma;
			std::istringstream is{ s };
			is >> coords.first >> comma >> coords.second;
			return coords;
			};

		std::transform(std::istream_iterator<std::string>(readFile), std::istream_iterator<std::string>(),
			std::back_inserter(points), f);

		readFile.close();
	}
	else std::cout << "Unable to open file"; 

	std::vector<double> diffVector(points.size() - 1); 
	std::transform(points.begin(), points.end() - 1, points.begin() + 1, diffVector.begin(), pythagoras);

	double distance = std::accumulate(diffVector.begin(), diffVector.end(), 0.0); 

	std::cout << "The points: " << std::endl; 
	std::ostream_iterator<std::string> out{ std::cout, "\n" }; 
	std::transform(points.begin(), points.end(), out, [](std::pair<int, int> o) { return "(" + std::to_string(o.first)
		+ "," + std::to_string(o.second) + ")"; });
	std::cout << "\nDistance travelled = " << distance; 

}