#ifndef bengisuozdemir_Ozdemir_Bengisu_hw5_header_h
#define bengisuozdemir_Ozdemir_Bengisu_hw5_header_h
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
.h and corresponding .cpp files were created for overloading homework purposes
by Bengisu Ozdemir ID:26683
*/
struct Money
{
	string currency;
	double amount;
	//default constructor
	Money ()
		:currency(), amount()
	{}
	//constructor
	Money(string _currency, double _amount)
		:currency(_currency), amount(_amount)
	{}
};
class Wallet
{
private:
	Money * curar; //currencyArray
	int size; //size of the stack
public:
	Wallet(); //default constructor
	Wallet(const Wallet &); //copy constructor
	~Wallet(); //destructor
	Money * createClone () const; //to create deep copy
	Money *getCurrency() const; //returns the currencies
	Wallet operator+(const Money& mon) const; //overloading "+" op (Wallet + Money).
	Wallet operator-(const Money& mon) const; //overloading "-" op (Wallet - Money).
	Wallet operator+(const Wallet& rhs) const; //overloading "+" op (Wallet + Wallet).
	const Wallet & operator = (const Wallet &); //overloading "=" op (Wallet = Wallet).
	const Wallet & operator+=(const Wallet& rhs); //overloading "+=" op (Wallet += Wallet).
	bool operator==(const Wallet& rhs) const; //overloading "==" op (Wallet == Wallet).
	void deleteList(); //to delete an array
	int getSize() const; //returns the size of the stack
};

//free functions
ostream & operator << (ostream &, const Wallet &); //overloading "<<" op (cout <<).
bool operator>=(const Wallet& wal, const Money& mon); //overloading ">=" op (Wallet >= Money).
bool operator<=(const Money& mon, const Wallet& wal); //overloading "==" op (Money <= Wallet).

#endif bengisuozdemir_Ozdemir_Bengisu_hw5_header_h