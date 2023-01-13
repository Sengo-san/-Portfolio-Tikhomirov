#include "Header.h"

int main()
{
	char s[20];//slovo
	char text[80];//text
	

	for (int i = 0; i < 3; i++)
	{
		cout << "enter slovo:";
		gets_s(s);
		cout << endl << "enter text:";
		gets_s(text);

		if (BM_search(s, text)==1)
			cout << endl << "YES"<<endl << endl;
		else cout << endl << "NO" << endl << endl;
	}

}