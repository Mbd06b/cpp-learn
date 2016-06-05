#ifndef C_AREACODE_H
#define C_AREACODE_H
#include "Digits.h"

class C_AreaCode : public Digits<3>
	{
		public:
			C_AreaCode	(	)									{	};
			C_AreaCode	(char AC[])				:AreaCode(AC)	{	};
			C_AreaCode	(const C_AreaCode&AC)	:AreaCode(AC)	{	};
			~C_AreaCode	(	)									{	};
	
		private:
		
	};

inline istream& operator >> (istream& in, C_AreaCode& AC)
	{
		AC.Digits::Read(in); 
		return (in);
	}

inline ostream& operator << (ostream& out, const C_AreaCode& AC)
	{
		for (int i = 0; i < 3; i++)	out << AC[i];
		return out;
	}



#endif
