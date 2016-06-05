#ifndef Name_H
#define Name_H
#include <string>
#include <iomanip>
#include <iostream>
using namespace std; 



class Name
	{
		public: 
				Name		(	);
				Name		(const Name &);
				Name		(const string &, const string &, const string &);
				~Name		(	);
				
				Name&       SetName		(const	string &, const string &, const string &);
				bool		SetFirst	(const	string&);
				bool		SetMiddle	(const	string&);
				bool		SetLast		(const	string&);
				bool		Compare		(const	Name&)		const;
				bool		Compare		(const	string&)	const;
				Name &		operator =	(const	Name&);
				bool		operator ==	(const	Name&)		const;
				bool		operator ==	(const	string&)	const;
				bool		operator <	(const	Name&)		const;
				bool		operator <	(const	string&)	const;
				bool		operator >	(const	Name&)		const;
				bool		operator >	(const	string&)	const;
				istream&	Read		(istream&);
		const	string&		GetFirst	(	)						const;
		const	string&		GetMiddle	(	)						const;
		const	string&		GetLast		(	)						const;
		const	Name&       GetName     (	)                       const; 
				void		Display		(	)						const; 


		private: 
				string		First; 
				string		Middle; 
				string		Last; 
	}; 

ostream & operator << (ostream&, const Name &);

istream & operator >> (istream&, Name &); 

inline void Name::Display () const
	{
		cout << First << " (" << Middle << ") " << Last; 
	}

inline const string & Name::GetFirst()	const
	{
		return First; 
	}

inline const string &Name::GetMiddle()	const
	{
		return Middle; 
	}

inline const string &Name::GetLast()	const
	{
		return Last; 
	}

inline const Name& Name::GetName()    const
	{
		return *this; 
	}

inline bool Name::SetFirst (const string& Str)
	{
		First = Str;
		return true;
	}

inline bool Name::SetMiddle (const string& Str)
	{
		Middle = Str;
		return true;
	}

inline bool Name::SetLast (const string& Str)
	{
		Last = Str;
		return true;
	}
inline Name& Name::SetName(const string& F, const string& M, const string& L)
	{
		SetLast(L);
		SetMiddle(M);
		SetFirst(F); 
		return *this; 
	}

#endif
