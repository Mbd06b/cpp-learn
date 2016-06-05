#ifndef Address_H
#define Address_H
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <iostream>
using namespace std; 

#include "Digits.h"
#include "Zone_IP.h"

class Address
	{
		public: 
				Address		(	);
				Address		(const Address&);
				Address		(const string&, const string&, const Zone_IP&, const string&);
				~Address	(	);

				void			SetAddress	(const string&, const string&, const Zone_IP&, const string&);
		const	string&			GetStreet	(	)					const;
		const	string&			GetCity		(	)					const;
				ostream&		Get_Zip		(ostream&)				const;
		const	string&			GetState	(	)					const;
		const   Address&		Get_Address	(	)					const;
				ostream&		Display		(ostream&)				const;
				void			SetStreet	(const string&); 
				void			SetCity	    (const	string&); 
				void			SetZip		(const	ZipCode&); 
				void			SetState	(const	string&);
				istream&		Read		(		istream&); 
				bool			Compare		(const	Address&)		const;
				bool			operator ==	(const	Address&)		const; 
				Address&		operator =	(const	Address&);  
				Address&		operator =	(const	string& );
				Address&		operator =	(const	Zone_IP&);
				bool			operator <	(const	Address&)		const;
				bool			operator <	(const	string&)		const; 
				bool			operator >	(const	Address&)		const;
				bool			operator >  (const	string&)		const; 
				bool			operator >	(const Zone_IP&)		const;

		private: 
				string			Street; 
				string			City; 
				string			State;
				Zone_IP			Zip; 
	};

ostream & operator << (ostream&, const Address &);

istream & operator >> (istream&, const Address &); 

inline ostream& Address::Display (ostream& out) const
	{
		
		 out << Street << endl;

		 out << City << " " << State << ", " << Zip; 
		return out; 
	}

inline const string & Address::GetStreet () const
	{
		return Street; 
	}

inline const string& Address::GetCity () const
	{
		return City; 
	}

inline const string& Address::GetState(	)const
	{
		return State;
	}

inline const Address& Address::Get_Address(	)const
	{
		return *this;
	}

inline void Address::SetStreet(const string&S)
	{
		Street = S;
	}

inline ostream& Address::Get_Zip(	ostream&out	)const
	{
		return Zip.Zone_IP::Get_Zip(out); 
	}

inline void Address::SetCity(const string& Str)
	{
		City = Str;
	}

inline void Address::SetZip(const ZipCode& ZP)
	{
		(Zip.Zone_IP::Set_Zip(ZP));
	}

inline void Address::SetState(const string& Str)
	{
		State = Str; 
	}

inline void Address::SetAddress(const string&S, const string&C, const Zone_IP& Z, const string& ST)
	{
		SetState	(ST);
		SetCity		(C);
		SetStreet	(S); 
		SetZip		(Z);
	}

#endif