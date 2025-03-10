#include"functie.h"
#include<cstring>
int movie_compare_name(Movie a, Movie b)
{ 
	const char* pa = a.get_name();
	const char* pb = b.get_name();
	int na = strlen(pa);
	int nb = strlen(pb);
	int i = 0;
	for (i = 0;pa[i] && pb[i];i++)
		if (pa[i] < pb[i])return -1;
		else if (pa[i] > pb[i])return 1;
	if (pa[i])return 1;
	if (pb[i])return -1;
	return 0;
}
int movie_compare_year(Movie a, Movie b)
{ 
	int yeara = a.get_year();
	int yearb = b.get_year();
	if (yeara < yearb)return -1;
	else if (yeara > yearb)return 1;
	else return 0;
}
int movie_compare_score(Movie a, Movie b)
{ 
	double IMDBa = a.get_IMDB();
	double IMDBb = b.get_IMDB();
	if (IMDBa < IMDBb)return -1;
	else if (IMDBa > IMDBb)return 1;
	else return 0;
}
int movie_compare_length(Movie a, Movie b)
{ 
	int lga = a.get_length();
	int lgb = b.get_length();
	if (lga < lgb)return -1;
	else if (lga > lgb)return 1;
	else return 0;
}
int movie_compare_passed_years(Movie a, Movie b)
{ 
	int pyeara = a.passyear();
	int pyearb = b.passyear();
	if (pyeara < pyearb)return -1;
	else if (pyeara > pyearb)return 1;
	else return 0;
}
