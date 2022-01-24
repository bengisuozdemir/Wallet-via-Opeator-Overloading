#include "bengisuozdemir_Ozdemir_Bengisu_hw5_header.h"
Wallet::Wallet()
{//Constructor
	curar = NULL;
	size = 0;
}
Wallet::~Wallet()
{//Destructor
	delete [] curar;
}
Wallet::Wallet(const Wallet & copy)
{//Copy Constructor
	size = copy.size;
    curar = new Money [size];

    for (int i = 0; i < size; i++)
    {
        this->curar[i]=copy.curar[i];
    }
}
Money * Wallet::createClone () const
{//to create a clone by deep copy
	Money * ptr;
	ptr = new Money [size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = curar[i];
	}
	return ptr;
}
void Wallet::deleteList ()
{//to delete an array
	delete [] curar;
	curar = NULL;
}
const Wallet & Wallet::operator = (const Wallet & rhs) //must be a member fuction
{//beginning: taken from  linkedlistextraoper.cpp, modified by Bengisu Ozdemir
	if (this != &rhs)
	{
		deleteList(); // same as this->deleteList()
		curar = rhs.createClone();
		size = rhs.size;
	}
	return *this; //must have a return value
}//ending: linkedlistextraoper.cpp
int Wallet::getSize() const
{//to export the size item
	return size;
}
Money * Wallet::getCurrency() const
{//to export the currency item
	return curar;
}
ostream & operator << (ostream & os, const Wallet & wall)
{//to overload "<<" operator
	if(wall.getSize() != 0)
	{
		Money * ptr = wall.getCurrency();
		for (int i = 0; i < wall.getSize(); i++)
		{
			os << ptr[i].currency << " " << ptr[i].amount;
			if(i != wall.getSize()-1)
				os << " - ";
			
		}
	}
   return os;
}
Wallet Wallet::operator+(const Money& mon) const
{//to overload "+" operator
	for (int i = 0; i < size; i++)
	{
		if(curar[i].currency == mon.currency)
		{
			Wallet tempWal(*this);
			tempWal.curar[i].amount += mon.amount;
			return tempWal;
		}
	}
	Wallet newWal;
	newWal.size = size+1;
	newWal.curar = new Money[size+1];
	for (int i = 0; i <size; i++)
	{
		newWal.curar[i] = this->curar[i];
	}
	newWal.curar[newWal.size-1] = mon;
	return newWal;
}
Wallet Wallet::operator-(const Money& mon) const
{//to overload "-" operator
	for (int i = 0; i < size; i++)
	{
		if(curar[i].currency == mon.currency)
		{
			Wallet tempWal(*this);
			if(tempWal.curar[i].amount > mon.amount)
			{
				tempWal.curar[i].amount -= mon.amount;
				return tempWal;
			}
			else if(tempWal.curar[i].amount == mon.amount)
			{
				if(size != 1)
				{
					Money * tempMon = new Money[size-1];
					for (int j = 0; j < i; j++)
					{
						tempMon[j] = tempWal.curar[j];
					}
					for (int k = i+1; k < size; k++)
					{
						tempMon[k-1] = tempWal.curar[k];
					}
					delete [] tempWal.curar;
					tempWal.curar = tempMon;
					tempWal.size--;
					return tempWal;
				}
				else
				{
					delete [] tempWal.curar;
					tempWal.curar = NULL;
					tempWal.size--;
					return tempWal;
				}
			}
			else
			{
				return tempWal;
			}
		}
	}
	return *this;
}
bool operator<=(const Money& mon, const Wallet& wal)
{//to overload "<=" operator
	if (wal >= mon)
		return true;
	return false;
}
bool operator>=(const Wallet& wal, const Money& mon)
{//to overload ">=" operator
	for (int i = 0; i < wal.getSize(); i++)
	{
		if(wal.getCurrency()[i].currency == mon.currency && wal.getCurrency()[i].amount >= mon.amount)
			return true;
	}
	return false;
}
bool Wallet::operator==(const Wallet& rhs) const
{//to overload "==" operator
	if(size != rhs.size)
	{
		return false;
	}
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			bool check = false;
			for (int j = 0; j < rhs.size; j++)
			{
				if(this->curar[i].currency == rhs.curar[j].currency && this->curar[i].amount == rhs.curar[j].amount)
					check = true;
			}
			if (!check)
				return false;
		}
	}
	return true;
}
Wallet Wallet::operator+(const Wallet& rhs) const
{//to overload "+" operator
	Wallet tempWal(*this);
	for (int i = 0; i < rhs.size; i++)
	{
		tempWal = tempWal + rhs.curar[i];
	}
	return tempWal;
}
const Wallet & Wallet::operator+=(const Wallet& rhs)
{//to overload "+=" operator
	*this= *this + rhs;
	return *this;
}