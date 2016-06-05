#include "Name.h"
#include "string.h"

Name::Name ()
{
}

Name::Name (const Name& N):First (N.First),Middle (N.Middle),Last (N.Last)
{
}


Name::Name (const string& F, const string& M, const string& L):First (F), Middle(M), Last(L)
{
}

Name::~Name()
{
}


Name& Name::operator = (const Name & N)
	{
		First	= N.First;
		Middle	= N.Middle;
		Last	= N.Last;
		return *this; 
	}

bool Name::operator < (const string& Str) const
	{
		if (Last < Str)
			return true;
		else
			if (Last == Str)
				if (First < Str) 
					return true;
			else
				if (First == Str)
					if (Middle < Str)
							return true;
					else return false;
				else return false;
			else return false;
	}

bool Name::operator < (const Name& N) const
	{
		if (Last < N.Last)
			return true;
		else
			if (Last == N.Last)
				if (First < N.First)
					return true;
				else
					if (First == N.First)
						if (Middle < N.Middle)
							return true;
						else return false;
					else return false;
			else return false; 
	}

bool Name::operator >(const string& Str) const
	{
		if (Last > Str)
			return true;
		else
			if (Last == Str)
				if (First > Str)
				return true;
			else
				if (First == Str)
					if (Middle > Str)
					return true;
				else return false;
			else return false;
		else return false;
	}

bool Name::operator > (const Name & N) const
	{
		if (Last > N.Last)
			return true;
		else
			if (Last == N.Last)
				if (First > N.First)
					return true;
				else
					if (First == N.First)
						if (Middle > N.Middle)
							return true;
						else return false;
					else return false;
			else return false; 
	}

ostream& operator << (ostream& out, const Name& N)
	{
		out << N.GetFirst() << " (" << N.GetMiddle() << ") " << N.GetLast();
		return out; 
	}

#pragma warning(disable : 4996)
istream& Name::Read (istream& in)
	{
		char		line[81];
		const char	tokeD[] = " ";
		char		*Ptr;

		cout << setw(18) << right << "NAME{F M L}: ";
		in.getline(line, 81); 
			Ptr = strtok(line, tokeD);	First = Ptr;
			Ptr = strtok(NULL, tokeD);	Middle = Ptr;
			Ptr = strtok(NULL, tokeD);	Last = Ptr; 

		return in; 
	}

istream& operator >> (istream& in, Name& N)
	{
		return N.Read(in); 
	}

bool Name::operator == (const Name& N)const
	{
		if ((Last == N.Last) && (First == N.First) && (Middle == N.Middle))
			return true; else return false; 
	}

bool Name::operator == (const string& Str)const
	{
		if ((Last == Str) && (First == Str) && (Middle == Str))
			return true; else return false;
	}

bool Name::Compare(const Name& N)const
	{
		if ((Last == N.Last) && (First == N.First) && (Middle == N.Middle))
			return true; else return false;
	}

bool Name::Compare(const string& Str)const
	{
		if ((Last == Str) && (First == Str) && (Middle == Str))
			return true; else return false;
	}



