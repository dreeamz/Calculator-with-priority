#include <iostream>


void fillExpressionBuffer(char *buffer)
{
	std::cin.getline(buffer, 250);
}
bool isValidSymbol(char sym)
{
	if (sym >= 48 && sym <= 57 || sym >= 40 && sym <= 43 || sym == 45 || sym == 47)
		return true;
	return false;
}
//  time O(n) 
// space O(n)
char *getMathExpressionFromBuffer(char *buffer, int m_expression_size)
{
	char *math_expression = new char[m_expression_size + 1];

	for (int m_i = 0,i = 0; m_i < m_expression_size + 1 && buffer[i] != 0; i++)
		if (isValidSymbol(buffer[i])){
			math_expression[m_i] = buffer[i];
			m_i++;
		}

	return math_expression;
}
//O(n)
int getMathExpressionSizeFromBuffer(char *buffer)
{
	int i = 0, size = 0;

	for (int i = 0; buffer[i] != '\0'; i++)
		if (isValidSymbol(buffer[i]))
			size++;

	return size;
}

int calculateExpression(char *)
{

}

int getMathExpressionResult(char *m_expression)
{
	for(int i = 0; m_expression[i]!='\0';i++)
	{
		
	}
}

int main()
{
	char *buffer = new char[250];
	fillExpressionBuffer(buffer);

	int size = getMathExpressionSizeFromBuffer(buffer);
	char *math_expression = getMathExpressionFromBuffer(buffer, size);
	delete[] buffer;

	std::cout << math_expression;
	std::cout << '\n';
	return 0;
}
