#ifndef DIGITS_H
#define DIGITS_H
#include <assert.h>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

template <int Length>
	class Digits
		{
		public:
				enum	Exceptions {OK, IndexOutOfBounds, InvalidSize};
				Digits		(	);
				Digits		(const Digits <Length> &);
				Digits		(char[]);
				~Digits		(	);

				Digits <Length> &	Copy			(const Digits <Length> &);
				Digits <Length> &	operator =		(const Digits <Length> &);
				Digits <Length> &	operator =		(char[]);
				bool				operator ==		(const Digits <Length> &)	const;
				bool				operator >		(const Digits <Length> &)	const;
				bool				operator <		(const Digits <Length> &)	const;
				bool				operator !=		(const Digits <Length> &)	const;
				bool				Compare			(const Digits <Length> &)	const; 
				istream&			Read			(istream&); 
				ofstream&			Write			(ofstream&)					const;
				ostream&			Display			(ostream&)					const;
				char				Read_Char		(istream&); 
				char &				operator []		(int);
				char				operator []		(int)						const;
				int					Size			(	)						const;
			
				Exceptions	GetAt					(int, char &)				const;
				Exceptions	SetAt					(int, char);

				//vector <char>	Data;
 
		protected:
				vector <char>	Data;
			
		
		};

typedef Digits <5>	    ZipCode;
typedef Digits <9>	    Identity;
typedef Digits <3>		AreaCode;
typedef Digits <7>      PhoneNumber;

template <int Length>
	Digits <Length>::Digits (   ): Data (Length)
		{
		}

template <int Length>
	Digits <Length>::Digits (const Digits <Length> & Dig): Data (Dig.Data)
		{
		}

template <int Length>
	Digits <Length>::Digits (char STR []): Data (Length)
		{
			int		i;		

			for (i = 0; i < Length; i++)
					Data[i] = STR[i];
		}

template <int Length>
	Digits <Length>::~Digits ()
		{
		}

template <int Length>
	typename Digits<Length>::Exceptions Digits<Length>::GetAt (int i, char & c) const
		{
			if ((i >= 0) && (i < Length))
					{
					c = Data [i];
					return OK;
					}
				else
					return IndexOutOfBounds;
		}

template <int Length>
	typename Digits<Length>::Exceptions Digits <Length>::SetAt (int i, char c)
		{
			if ((i >= 0) && (i < Length))
					{
					Data [i] = c;
					return OK;
					}
				else
					return IndexOutOfBounds;
		}

template <int Length>
	Digits<Length>&	Digits<Length>::operator =(const Digits <Length> & Dig)
		{
			Data = Dig.Data;
			return *this;
		}

template <int Length>
	Digits <Length>& Digits<Length>::Copy (const Digits <Length> & D)
		{
			int		i;

			for (i = 0; i < Length; i++)
				Data[i] = D[i];

		}

template <int Length>
	Digits<Length>& Digits<Length>::operator = (char Str [])
		{
			int		i;

			if (strlen (Str) == Data.size ())
					{
						for (i = 0; i < Data.size (); i++)
							Data [i] = Str [i];
							return *this;
					}
			else
					{
					cout << "invalid size"; 
					throw InvalidSize;
					}
		}

template <int Length>
	ofstream& Digits<Length>::Write(ofstream& os)const
		{
			char c;
			for (int i = 0; i < Length; i++)
				{
					c = Data[i];
					os = c;
				}

			return os;
		}

template <int Length>
	istream& Digits<Length>::Read(istream& in)
		{	
			char c; 
			for (int i = 0; i < Length ; i++)
				{
					in >> c;
					Data [i] = c;
				}

			return in; 
		}

template <int Length>
	ostream& Digits<Length>::Display(ostream& out) const
		{
			for (int i = 0; i < (Length); i++)
				cout << Data[i];
			return out; 
		}

template <int Length>
	int	Digits<Length>::Size(	)const
		{
			return Length; 
		}

template <int Length>
	char&	Digits<Length>::operator []	(int i)
		{
			if ((i >= 0) && (i < Length))
					return Data [i];
				else
					throw IndexOutOfBounds;
		}

template <int Length>
	char	Digits<Length>::operator []	(int i) const
		{
			if ((i >= 0) && (i <= (Length)))
					return Data [i];
				else
					throw IndexOutOfBounds;
		}

template <int Length>
	bool	Digits<Length>::operator ==	(const Digits <Length> & Dig)const
		{		
			return Data==Dig.Data;
		}

template <int Length>
	bool	Digits<Length>::operator <	(const Digits <Length> & Dig)const
		{		
			return Data<Dig.Data;
		}

template <int Length>
	bool	Digits<Length>::operator >	(const Digits <Length> & Dig)const
		{		
			return Data>Dig.Data;
		}

template <int Length>
	bool	Digits<Length>::operator !=	(const Digits <Length> & Dig)const
		{
			return Data!=Dig.Data;
		}

template <int Length>
inline ostream & operator << (ostream & out, const Digits <Length> & str){

//  out << str.pData;  //cannot do unless this is a friend since pData is private
	out << (const char *) str;
	return out;
}



#endif
