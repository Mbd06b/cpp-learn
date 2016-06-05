#include "Stud_Rcrd.h"

Stud_Rcrd::Stud_Rcrd(	)
{
}

Stud_Rcrd::Stud_Rcrd(const Stud_Rcrd& SR) :Student(SR.Student), Id(SR.Id), Adr(SR.Adr), Ac(SR.Ac), Ph(SR.Ph)
{
}

Stud_Rcrd::Stud_Rcrd(const Name&N, const Identification&I, const Address&A, const C_AreaCode&C, const Phone&P)
{
	Student = N; Id = I; Adr = A; Ac = C; Ph = P; 
}

Stud_Rcrd::~Stud_Rcrd(	)
{
}

void Stud_Rcrd::Set_Stud(const Stud_Rcrd& SR)
	{ 
		Student = SR.Student; Id = SR.Id; Adr = SR.Adr; Ac = SR.Ac;  Ph = SR.Ph; 
	}

#pragma warning(disable : 4996)
istream& Stud_Rcrd::Write_Rcrds(istream& cin)
	{
		Student.Name::Read(cin);

		cout << setw(18) << right << "STUDENT ID: ";
			Id.Identification::Read(cin);

		Adr.Address::Read(cin);

			cout << setw(18) << right << "PH{xxx-xxxxxxx}: ";
			const char	tokeD[] = "-";
			char		*Ptr;
			char		line[81];
			string		temp;

				cin.getline(line, 81);
				Ptr = strtok(line, tokeD);
				Ac = Ptr;
				Ptr = strtok(NULL, tokeD);
				Ph = Ptr; '\n'; 

		return cin;
	}

bool Stud_Rcrd::operator > (const Stud_Rcrd& SD)const
	{
		return Id > SD.Id; 
	}

bool Stud_Rcrd::operator < (const Stud_Rcrd& SD)const
	{
		return Id < SD.Id; 
	}

bool Stud_Rcrd::operator == (const Stud_Rcrd& SD)const
	{
		return Id == SD.Id; 
	}

int Stud_Rcrd::Compare_Name(const void* Str, const void* Str2)
{
	const Name* Stud1(reinterpret_cast<const Name*> (Str));
	const Name* Stud2(reinterpret_cast<const Name*> (Str2));

	if ((*Stud1).Name::GetLast() < (*Stud2).Name::GetLast())
		return -1;
		else if (*Stud1 > *Stud2)
			return 1;
	
		else return 0;
	}

ostream& Stud_Rcrd::Write_File(ostream& out)const
	{
		out << Student << '\n' << out << Id << '\n' 
			<< Adr << '\n' << Ac << "-"	<< Ph << "\n\n";

		return out; 
	}

bool Stud_Rcrd::Compare_ID(Identification A, Identification B)
	{
		return A < B; 
	}