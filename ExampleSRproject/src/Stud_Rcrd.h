#ifndef STUD_RCRD_H
#define STUD_RCRD_H

#include "Name.h"
#include "Phone.h"
#include "Address.h"
#include "C_AreaCode.h"
#include "Identification.h"
#include <fstream>
#include <stdlib.h>

	class Stud_Rcrd
		{
		public:
				Stud_Rcrd	(	);
				Stud_Rcrd	(const Stud_Rcrd&);
				Stud_Rcrd	(const Name&, const Identification&, const Address&, const C_AreaCode&, const Phone&);
				~Stud_Rcrd	(	);

				bool		Compare_ID		(Identification, Identification);
		static	int			Compare_Name(const void*, const void*);
				void		Set_Stud		(const Stud_Rcrd&);
				ostream&	Write_File		(ostream& out)				const;
				istream&	Write_Rcrds		(istream& in);
				void		Get_Rcrd		(	)						const; 
				void		Get_Id			(	)						const;
				bool		operator >		(const Stud_Rcrd&)			const;
				bool		operator <		(const Stud_Rcrd&)			const;
				bool		operator ==		(const Stud_Rcrd&)			const;

private:
				Name			Student;
				Identification	Id;
				Address			Adr;
				Phone			Ph;
				C_AreaCode		Ac;
	};

/*
inline istream& operator >> (istream& in, Stud_Rcrd& SR)
	{
		
	}*/

inline ostream& operator << (ostream& out, const Stud_Rcrd& SR)
	{
		SR.Get_Rcrd(); 
		return out;
	}

inline void Stud_Rcrd::Get_Rcrd()const 
	{
		cout << Student << endl;
		cout <<  Id << endl;
		cout << Adr << endl;
		cout << Ac << '-' << Ph << "\n" << endl;
	}

inline void Stud_Rcrd::Get_Id(	)const
	{
		cout << Id << endl; 
	}
	



#endif
	