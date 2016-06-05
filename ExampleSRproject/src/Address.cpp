// C4996 warning disabled

#include "Address.h"

Address::Address ()
{
}

Address::Address(const Address& A) : Street(A.Street), City(A.City), State(A.State), Zip(A.Zip)
{
}

Address::Address(const string& S, const string& C, const Zone_IP& Z, const string& St) : Street(S), City(C), State(St), Zip(Z)
{
}

Address::~Address()
{
}

Address & Address::operator = (const Address& A)
	{
		Street = A.Street;
		City = A.City;
		Zip = A.Zip; 
		State = A.State;
		return *this; 
	}

bool Address::operator < (const Address& A) const
	{
		if (Zip < A.Zip)
			return true;
		else
			if (Zip == A.Zip)
				if (City < A.City)
					return true;
				else
					if (City == A.City)
						if (Street < A.Street)
							return true;
						else return false;
					else return false;
			else return false; 
	}

bool Address::operator > (const Address& A) const
	{
			if (Zip > A.Zip)
			return true;
		else
			if (Zip == A.Zip)
				if (City > A.City)
					return true;
				else
					if (City == A.City)
						if (Street > A.Street)
							return true;
						else return false;
					else return false;
			else return false; 
	}

ostream& operator << (ostream& out, const Address& A)
	{
		A.Display(out);
		return out; 
	}

#pragma warning(disable : 4996)
istream& Address::Read (istream& in)
	{
		cout << setw(18) << right << "ADDRESS: "; '\b\b';
		in.ignore(1);
		getline(in, Street); 
	 
		const char	tokeS[] (" ");
		const char	tokeD[] = "-";
		char		*Ptr;
		char		line[81];
	
		cout << setw(18) << right << " "; 
		in.getline(line, 81);
		Ptr = strtok(line, tokeS);	City = Ptr;
		Ptr = strtok(NULL, tokeS);	State = Ptr; 
		Ptr = strtok(NULL, tokeS);	Zip = Ptr; 
		return in; 
	}

istream& operator >> (istream& in, Address& A)
{
	return A.Read(in); 
}

bool Address::operator == (const Address& A)const
{
	return (*this).Compare(A);
}


bool Address::Compare(const Address& A)const
{
	if(	(State == A.State) && (Zip == A.Zip) && 
		(City == A.City) && (Street == A.Street))
		return true;
	else return false;
}

