/*****************************************
 * Lab 3: exercise 1                      *
 ******************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>

int main() {
	std::string lender; 
	std::string borrower; 
	int price; 

	std::map<std::string, int> loanMap; 

	std::cout << "Enter list of friend-to-friend loans:\n";


	while (std::cin >> lender >> borrower >> price) {
		loanMap[lender] += price;
		loanMap[borrower] -= price;	
	}

	std::vector<std::pair<std::string, int>> loanVector(loanMap.begin(), loanMap.end()); 
	std::sort(loanVector.begin(), loanVector.end(), 
	[](const auto& a, const auto& b)-> bool { return a.second > b.second; }); 

	std::cout << "Name     Balance\n"; 
	std::ostream_iterator<std::string> it_out{ std::cout, "\n"};
	std::transform(loanVector.begin(), loanVector.end(), it_out, [](const auto& l) { return l.first + "       " + std::to_string(l.second); });

	// steg 3 summera
	int loanSum = std::accumulate(loanVector.begin(), loanVector.end(), 0, 
		[](int value, const std::pair<std::string, int>& V) { 
			return (V.second > 0) ? (value + V.second) : value; 
		});
	int loanCounter = std::accumulate(loanVector.begin(), loanVector.end(), 0,
		[](int value, const std::pair<std::string, int>& V) {
			return (V.second > 0) ? (++value) : value;
		});
	int meanLoan = loanSum / loanCounter; 

	int debtSum = std::accumulate(loanVector.begin(), loanVector.end(), 0,
		[](int value, const std::pair<std::string, int>& V) {
			return (V.second < 0) ? (value + abs(V.second)) : value;
		});
	int debtCounter = std::accumulate(loanVector.begin(), loanVector.end(), 0,
		[](int value, const std::pair<std::string, int>& V) {
			return (V.second < 0) ? (++value) : value;
		});
	int meanDebt = debtSum / debtCounter;

	std::cout << std::endl << "Mean loan amount: " << meanLoan << std::endl << "Mean debt amount: " << meanDebt << std::endl;

}
 
 /* read list of loans payer-receiver read while-loop och std::cin, total std::map
AE EM 102 
AN PS 190 
EM BD 23 
CK EM 15 
FF CK 17 
AE CK 9 
PS FF 50 
DH FF 35 
DH EM 65 
PS AN 75 
FF CK 18 
AE EM 91 
JP FF 203 
*/

// output loans först störst-minst, sen debts (-) minst-störst med vector sort, ostream_iterator, INGA STANDARD LOOPS!

// display mean loan, sen mean debt (+) std::accumulate, INGA STANDARD LOOPS!
