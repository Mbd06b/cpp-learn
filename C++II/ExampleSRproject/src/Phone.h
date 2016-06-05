#ifndef PHONE_H
#define PHONE_H

#include "Digits.h"
#include <vector>

class Phone : public Digits<7>
	{						
		public:
				Phone		(				):PhoneNumber(	)	{	};
				Phone		(char PN[]		):PhoneNumber(PN)	{	};
				Phone		(const Phone&PN	):PhoneNumber(PN)	{	};
				~Phone		(		)							{	};

				Phone&	operator =	(char[]);
		private:
    };

inline istream& operator >> (istream& in, Phone& PN)
	{
		PN.Digits::Read(in); 
		return (in);
	}

inline ostream& operator << (ostream& os, const Phone& PN)
	{
		for (int i = 0; i < 7; i++)	os << PN[i];
		return os;
	}

inline 	Phone&	Phone::operator = (char T[])
	{
		int		i;

		for (i = 0; i < 7; i++)
			{
				Data[i] = T[i];
			}
		return *this; 
	}

#endif






