#include"functie.h";
#include<cstring>;
int cmpnm(Student a, Student b)
{
	char numea[105], numeb[105];
	a.get_name(numea);
	b.get_name(numeb);
	int na=strlen(numea);
	int nb=strlen(numeb);
	int i = 0;
	for (i = 0;numea[i] != ' ' && numeb[i] != ' ';i++)
		if (numea[i] > numeb[i])return 1;
		else if (numea[i] < numeb[i])return -1;
	if (numea[i] != ' '&&numeb[i]==' ')return 1;
	if (numeb[i] != ' ' && numea[i] == ' ')return -1;
	for (i;numea[i]&& numeb[i];i++)
		if (numea[i] > numeb[i])return 1;
		else if (numea[i] < numeb[i])return -1;
	return 0;
}
int cmpmath(Student a, Student b)
{
	float gra, grb;
	gra = a.get_math();
	grb = b.get_math();
	if (gra > grb)return 1;
	else if (gra < grb)return -1;
	return 0;
}
int cmpeng(Student a, Student b)
{
	float gra, grb;
	gra = a.get_eng();
	grb = b.get_eng();
	if (gra > grb)return 1;
	else if (gra < grb)return -1;
	return 0;
}
int cmphis(Student a, Student b)
{
	float gra, grb;
	gra = a.get_his();
	grb = b.get_his();
	if (gra > grb)return 1;
	else if (gra < grb)return -1;
	return 0;
}
int cmpavg(Student a, Student b)
{
	float gra, grb;
	gra = a.average();
	grb = b.average();
	if (gra > grb)return 1;
	else if (gra < grb)return -1;
	return 0;
}

