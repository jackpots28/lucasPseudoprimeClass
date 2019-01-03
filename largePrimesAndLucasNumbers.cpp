
#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <execution>

using namespace std;
using std::unique_ptr;

template <class T>
class lucasNumbers {
public:
	lucasNumbers() {
		cout << "-Object created-" << endl;

		lucasVec.resize(92);
		lucasVec.at(0) = 1;
		lucasVec.at(1) = 3;
		for (int i = 2; i < lucasVec.size(); i++) {
			lucasVec.at(i) = lucasVec.at(i - 1) + lucasVec.at(i - 2);
		}

		sizeOfVec = lucasVec.size();
	}

	~lucasNumbers() {
		lucasVec.clear();
		cout << "-Object destroyed-" << endl;
	}

	void clrVec() {
		lucasVec.clear();
		sizeOfVec = lucasVec.size();
	}

	void getSizeOfVec() {
		cout << sizeOfVec;
	}

	void prntContntsOfVec() {
		int j = 0;
		while (j < lucasVec.size()) {
			cout << lucasVec.at(j) << endl;
			++j;
		}
	}

	/* -idea behind "testIfPrime()"-
	* if lucasVec.at(n) - 1 is a multiple 
	* of test number 'n'. Then 'n' is a pseudo prime
	* n = test number, lucasVec.at(n) -1 % n == 0 -> return true 'prime'
	*/
	bool testIfPrime() {};

	void prntPrimeVect() {};

private:
	vector<unsigned long long int> lucasVec;
	vector<unsigned long long int> vectorOfPrimes;

	int sizeOfVec = 0;
	T testPrime;
};

int main() {
	unique_ptr<lucasNumbers<int>> obj1 (new lucasNumbers<int>);

	return 0;
}

