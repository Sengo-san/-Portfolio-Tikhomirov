#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

int BM_search(char* s, char* text)
{
	int m = strlen(s), n = strlen(text);
	
	//претрансляция
	int T[256], i, j, k;
	for (i = 0; i < 256; i++) T[i] = m;
	i = 0;
	while (i < m - 1)
	{
		T[s[i]] = m - 1 - i;
		i++;
	}
	//поиск
	i = m - 1;
	j = i;

	while (i < n)
	{
		if (j >= 0)
		{
			//сравнение	
			k = i;
			j = m - 1;
			while (text[k] == s[j])
			{
				if (j <= 0) return 1;
				j--; k--;
			}
			//сдвиг
			i = i + T[text[i]];
			j = m - 1;
		}

		else
			if(j >= 0)
			return 0;
		//else i = 1 - m;//???
			else return 1;


	}
	
	if (j >= 0)
		return 0;
	//else i = 1 - m;//???
	else return 1;

}