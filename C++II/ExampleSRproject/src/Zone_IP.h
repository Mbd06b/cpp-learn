#ifndef ZONE_IP_H
#define ZONE_IP_H
#include "Digits.h"
#include <iostream>
using namespace std;


class Zone_IP:	public Digits<5>
{
public:
	Zone_IP	(	):ZipCode(){};
	Zone_IP(char Z[]):ZipCode(Z){ };
	
	~Zone_IP			(	)	{};
	//Zone_IP &	operator =		(const Zone_IP &);
	Zone_IP &	operator =		(char[]);
	ostream& Get_Zip(ostream& )const;
	Zone_IP&	Set_Zip(const ZipCode&);



private:


};
inline istream& getline (istream& in, Zone_IP& Z)
{
		Z.Digits::Read(in); 
		return in; 	
}

inline istream& operator >> (istream& in, Zone_IP ZC) 
	{
		ZC.Digits::Read(in); 
		return in; 
	}

inline ostream& operator << (ostream& out, const Zone_IP& ZC) 
	{

		for (int i = 0; i < 5; i++)	out << ZC[i];
		return out;
	}
inline Zone_IP& Zone_IP::operator =	(char	Z	[])
{
	for (int i = 0; i < 5; i++)	Data[i] = Z[i];
	return *this;
}

inline Zone_IP& Zone_IP::Set_Zip(const ZipCode& ZC)
	{
		for (int i = 0; i < 5; i++)	Data[i] = ZC[i];
		return *this; 
	}

inline ostream& Zone_IP::Get_Zip(ostream& out)const
{
	for (int i = 0; i < 5; i++)	
		cout << Data[i];
	return out; 
	
}






#endif;