#include <iostream>
#include <ctime>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;

int razmer_vsego(char* a) {
	for (int i = 0; ; i++)
	{
		if (a[i] == 0)
		{
			return i + 1;
		}
	}
}
/////
int zapolneniye_charmass(char* a) {
	for (int i = 0, size1 = 0; ; i++)
	{
		if (a[i] == 42 || a[i] == 43 || a[i] == 45 || a[i] == 47)
		{
			size1++;
		}
		else if (a[i] == 0)
		{
			return size1;
		}
	}
}
/////
int zapol_intmass(char* a) {
	int temp = 0;
	int ba = 0;
	int ca = 0;
	int da = 0;
	for (size_t i = 0;; i++)
	{
		if (a[i] >= 48 && a[i] <= 58)
		{
			if (temp == false)
			{
				temp = true;
				da = 1;
			}
			if (ba == 0)
			{
				if (a[i] >= 48 && a[i] <= 58)
				{
					da = da * (a[i] - 48);
				}
			}
			else
			{
				da = da * 10 + a[i] - 48;
			}
			ba++;
		}
		else
		{
			if (temp == true)
			{
				ca++;
				if (a[i] == 0)
				{
					return ca;
				}
			}
			ba = 0;
			temp = false;
		}
	}
}

int dlina_umdel(char* arr3, int size) {
	int size4 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr3[i] == '*' || arr3[i] == '/')
		{
			size4++;
		}
	}
	return size4;
}

int resheniye(char* arr3, int size) {

	int size1 = zapol_intmass(arr3);
	int* arr1 = new int[size1];

	int size2 = zapolneniye_charmass(arr3);
	char* arr2 = new char[size2];

	int size4 = dlina_umdel(arr3, size);
	char* arr4 = new char[size4]; //mass umnojeniy i deleniy

	int* arr5 = new int[size4];//index umnojeniy i deleniy

	int a = 0;
	int temp = 0;
	int b = 0;
	int c = 0;
	int ca = 0;
	int dada = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr3[i] >= 48 && arr3[i] <= 58)
		{
			if (temp == false)
			{
				temp = true;
				ca = 1;
			}
			if (a == 0)
			{
				if (arr3[i] >= 48 && arr3[i] <= 58)
				{
					ca = (ca) * (arr3[i] - 48);

				}
			}
			else
			{
				ca = ca * 10 + arr3[i] - 48;
			}
			a++;
		}
		else
		{
			arr2[c] = arr3[i];
			c++;
			if (arr3[i] == '*' || arr3[i] == '/')
			{
				arr4[dada] = arr3[i];
				arr5[dada] = c;
				dada++;
			}
			if (temp == true)
			{
				arr1[b] = ca;
				b++;
			}
			a = 0;
			temp = false;
			ca = 0;
		}
	}

	int res = 0;
	int damba = false;

	for (int d = 0;; d++)
	{
		if (arr2[d] == '+' || arr2[d] == '-')
		{
			if (arr2[d + 1] == '/' || arr2[d + 1] == '*')
			{
				for (size_t a = d + 1;; a++)
				{
					if (arr2[a] == '/' || arr2[a] == '*')
					{
						if (a != d + 1)
						{
							switch (arr2[a])
							{
							case '*':temp *= arr1[a + 1];
								break;
							case '/':temp /= arr1[a + 1];
								break;
							}

						}
						else
						{
							switch (arr2[a])
							{
							case '*':temp = arr1[a] * arr1[a + 1];
								break;
							case '/':temp = arr1[a] / arr1[a + 1];
								break;
							}
						}
					}
					else
					{
						if (d == 0)
						{
							res = arr1[d];
							switch (arr2[d])
							{
							case '+':
								res = res + temp;
								break;
							case '-':
								res = res - temp;
								break;
							}
							d = a - 1;
							break;
						}
						else
						{
							switch (arr2[d])
							{
							case '+':
								res = res + temp;
								break;
							case '-':
								res = res - temp;
								break;
							}
							d = a - 1;
							break;
						}

					}
				}
			}
			else
			{
				if (d == 0)
				{
					switch (arr2[d])
					{
					case '+':res = arr1[d] + arr1[d + 1];
						break;
					case '-':res = arr1[d] - arr1[d + 1];
						break;
					}
				}
				else
				{
					switch (arr2[d])
					{
					case '+':res = res + arr1[d + 1];
						break;
					case '-':res = res - arr1[d + 1];
						break;
					}
				}

			}
		}
		else if (arr2[d] == 0)
		{
			break;
		}
		else
		{
			if (d == 0)
			{
				switch (arr2[d])
				{
				case '*':res = arr1[d] * arr1[d + 1];
					break;
				case '/':res = arr1[d] / arr1[d + 1];
					break;
				}
			}
			else
			{
				switch (arr2[d])
				{
				case '*':res = res * arr1[d + 1];
					break;
				case '/':res = res / arr1[d + 1];
					break;
				}
			}
		}

	}
	return res;
}
//10+20+5-800
int main()
{
	char* buffer = new char[250];
	cin.getline(buffer, 250);
	char* arr3 = _strdup(buffer);
	delete[]buffer;
	int size = razmer_vsego(arr3);

	int res = 0;
	res = resheniye(arr3, size);

	cout << "\n" << res;
	cout << "\n";
	cout << "\n";


	return 0;
}






