
#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <execution>

using namespace std;
using std::unique_ptr;
using std::execution::par_unseq;

const int vectorSize = 92;

template <class T>
class lucasNumbers {
public:
	lucasNumbers() {
		cout << "-Object created-" << endl;

		lucasVec.resize(vectorSize);
		lucasVec.at(1) = 1;
		lucasVec.at(2) = 3;
		for (int i = 3; i < lucasVec.size(); i++) {
			lucasVec.at(i) = lucasVec.at(i - 1) + lucasVec.at(i - 2);
		}
	}

	~lucasNumbers() {
		lucasVec.clear();
		vectorOfPrimes.clear();
		cout << "-Object destroyed-" << endl;
	}


	void prntLucasVect() {
		int j = 1;
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
	void testNumberForPrime(T val, bool& answer) {
		pos = distance(vectorOfPrimes.begin(), find(par_unseq, vectorOfPrimes.begin(), vectorOfPrimes.end(), val));
		if (pos >= vectorOfPrimes.size()) {
			if (((lucasVec.at(val) - 1) % val) == 0) {
				answer = true;
				vectorOfPrimes.push_back(val);
			}
			else
				answer = false;
		}
		else {
			answer = true;
		}
	}

	void testVecForPrimes(vector<T> testPrimes) {
		for (int i = 0; i < testPrimes.size(); i++) {
			pos = distance(vectorOfPrimes.begin(), find(par_unseq, vectorOfPrimes.begin(), vectorOfPrimes.end(), testPrimes.at(i)));
			if (pos >= vectorOfPrimes.size()) {
				if (((lucasVec.at(testPrimes.at(i)) - 1) % testPrimes.at(i)) == 0) {
					vectorOfPrimes.push_back(testPrimes.at(i));
				}
			}
		}
	}

	void clrVector() {
		vectorOfPrimes.clear();
	}

	void prntPrimeVect() {
		sort(vectorOfPrimes.begin(), vectorOfPrimes.end());
		cout << "Vector of primes contains: ";
		int i = 0;
		while (i < vectorOfPrimes.size()) {
			cout << vectorOfPrimes.at(i) << " ";
			++i;
		}
	}

private:
	ptrdiff_t pos;

	vector<unsigned long long int> lucasVec;
	vector<unsigned long long int> vectorOfPrimes;
};

int main() {
	bool response = false;
	bool flag = true;
	int value = 0;
	char whileInput = ' ';

	vector<int> test;
	for (int i = 1; i <= 90; i++) {test.push_back(i);}
	
	unique_ptr<lucasNumbers<int>> obj1 (new lucasNumbers<int>);

	while (flag) {
		cout << "(a)Test if number is prime | (b)Test a vector for primes | (c)Print vector of primes | (d)Clear vector (q)quit --> ";
		cin >> whileInput;

		if (tolower(whileInput) == 'q') {
			flag = false;
		}

		if (tolower(whileInput) == 'a') {
			cout << "Enter a number (1 to 91) to test: ";
			cin >> value;
			if (value > vectorSize -1) {
				cout << "Value is too great." << endl << endl;
			}
			else if (value <= 0) {
				cout << "Value is too small." << endl << endl;
			}
			else if (value <= vectorSize && value > 0) {
				obj1->testNumberForPrime(value, response);
				if (response == true) {
					cout << "Value: " << value << " is prime." << endl << endl;
					response = false;
					value = 0;
				}
				else
					cout << "Value is not prime." << endl << endl;
			}
		}

		if (tolower(whileInput) == 'b') {
			obj1->testVecForPrimes(test);
			cout << endl;
		}

		if (tolower(whileInput) == 'c') {
			obj1->prntPrimeVect();
			cout << endl << endl;
		}

		if (tolower(whileInput) == 'd') {
			obj1->clrVector();
			cout << endl << endl;
		}
	}
	return 0;
}

