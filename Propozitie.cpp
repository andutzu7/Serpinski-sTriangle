#include "Propozitie.h"

Propozitie::Propozitie()
{
	p = nullptr;
}

Propozitie::Propozitie(string s)
{
	Set(s);
}

void Propozitie::Set(string s)
{
	p = s;
}

int Propozitie::operator[](const char *cerinta)
{
	string aux(cerinta);
	string tc("total_chars");//total chars
	if (aux == tc)
	{
		int count = 0;
		for (int i = 0; i < p.size(); i++)
			if (p[i] != ' ')
				count++;
		return count;
	}
	string cc("count");//number of words
	if (aux == cc)
	{
		int wcount = 0;
		for (int i = 0; i < p.size(); i++)
			if (p[i] == ' ')
				wcount++;
		return wcount;

	}
	string vw("vowals");//nr of vowals
	if (aux == vw)
	{
		int vwcount = 0;
		for (int i = 0; i < p.size(); i++)
			if (p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u' || p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' || p[i] == 'U'  )
				vwcount++;
		return vwcount;
	}
	string nr("numbers");//nunbers
		if (aux == nr)
		{
			int ncount = 0;
			for (int i = 0; i < p.size(); i++)
			{
				if (p[i] == '1' || p[i] == '2' || p[i] == '3' || p[i] == '4' || p[i] == '5' || p[i] == '6' || p[i] == '7' || p[i] == '8' || p[i] == '9' || p[i] == '0')
					while (p[i] != ' ')
					{
						i++;
						if (p[i] == ' ')
							ncount++;
					}
			}
			return ncount;

	}//sunt prea stresat ca sa dau o solutie care nu e facepalm,sorry.
		
}

int Propozitie::getWcount()
{
	int wcount = 0;
	for (int i = 0; i < p.size(); i++)
		if (p[i] == ' ')
			wcount++;
	return wcount;
}

char* Propozitie::operator[](int index)
{
	int wcount = 0;
	int i;
	if (index < 0)
	index = getWcount() + index+1;//pt a afisa ultimele cuvinte in caz ca e negativ
	for (i = 0; i < p.size(); i++)
	{
		if (p[i] == ' ')
			wcount++;
		if (wcount == index)
			break;
	}
	i++;
	char* result = new char;
	int k = 0;
	while (p[i] != ' ')
		result[k++]=p[i++];

	return result;
}

int Propozitie::operator()(int nr)
{
	int final_nr = 0;
	int charcount = 0;
	for (int i = 0; i < p.size(); i++)
	{
		charcount++;
		if (p[i] == ' ')
			if (charcount-1 == nr)
			{
				final_nr++;
				charcount = 0;
			}
			else
				charcount = 0;
	}
	return final_nr;
	
}


