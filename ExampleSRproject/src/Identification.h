#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H
#include "Digits.h"


class Identification 
	{
		public:
				Identification	(		)                         {	};
				Identification	(char ID[]):Idy(ID)               { };
				Identification	(const Identity&ID)         {Idy.Digits::Copy(ID); };
				~Identification	(		)				          { };

				istream&		Read			(istream&);
                ostream&        Write           (ostream&);
                Identification& Loop            (const Identification&);
                Identification& operator =		(char []);
				bool			operator >		(const Identity&) const;
				bool			operator <		(const Identity&) const;
				bool			operator ==		(const Identity&) const;
           		bool			operator >		(const Identification&) const;
				bool			operator <		(const Identification&) const;
				bool			operator ==		(const Identification&) const;
				bool			operator !=		(const Identity&) const;
                char &			operator []		(int);
            	char			operator []		(int)			  const;
					
		private:
  
           Identity Idy;
	};

inline istream& operator >> (istream& in, Identification& ID) 
	{
		ID.Read(in);
		return (in);
	}

inline ostream& operator << (ostream& out, const Identification& ID)
	{
		   for (int i = 0; i < 9; i++)
			    {
				    out << ID[i];
			    }

		    return out; 
	}

inline Identification& Identification::operator = (char Id[])
    {
        Idy.Digits::operator=(Id);
    }

inline istream& Identification::Read(istream& in)
	{
	//	cout << setw(18) << right << "STUDENT ID: ";
		Idy.Digits::Read(in); return (in);
	}

inline ostream& Identification::Write (ostream& out)
    {
        for (int i = 0; i < 9; i++)
			    {
				    out << Idy[i];
			    }

		    return out; 
    }

inline bool	Identification::operator ==	(const Identity& Dig)const
	{
		return (Idy == Dig);
	}
inline bool Identification::operator > (const Identification& SD)const
	{
		return Idy > SD.Idy; 
	}

inline bool Identification::operator < (const Identification& SD)const
	{
		return Idy < SD.Idy; 
	}

inline bool Identification::operator == (const Identification& SD)const
	{
		return Idy == SD.Idy; 
	}
inline bool	Identification::operator < (const Identity& Dig)const
	{
		return (Idy < Dig); 
	}

inline bool	Identification::operator >	(const Identity& Dig)const
	{
		return (Idy > Dig);
	}

inline bool	Identification::operator !=	(const Identity& Dig)const
	{
		return (Idy != Dig);
	}
inline  char & Identification::operator [](int i)
    {
	    return Idy.Digits::operator[](i); 
    }
inline  char  Identification::operator []	(int i) const
    {
	    return Idy.Digits::operator[](i); 
    }

#endif
