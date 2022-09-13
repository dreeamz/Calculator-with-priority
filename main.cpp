#include <iostream>

void fillExpressionBuffer(char *buffer)
{
	std::cin.getline(buffer, 250);
}
bool isValidSymbol(char sym)
{
	// 0 - 10 , ( ) * + , - , /
	if (sym >= '0' && sym <= '9' || sym >= '(' && sym <= '+' || sym == '-' || sym == '/')
		return true;
	return false;
}
int getIntFromAsci(char sym)
{
	if (sym >= 48 && sym <= 57)
		return sym - 48;
	return -1;
}
//  time O(n)
// space O(n)
char *getMathExpressionFromBuffer(char *buffer, int m_expression_size)
{
	char *math_expression = new char[m_expression_size + 1];

	for (int m_i = 0, i = 0; m_i < m_expression_size + 1 && buffer[i] != 0; i++)
		if (isValidSymbol(buffer[i]))
		{
			math_expression[m_i] = buffer[i];
			m_i++;
		}

	return math_expression;
}
// O(n)
int getMathExpressionSizeFromBuffer(char *buffer)
{
	int i = 0, size = 0;

	for (int i = 0; buffer[i] != '\0'; i++)
		if (isValidSymbol(buffer[i]))
			size++;

	return size;
}

int calculateMathExpression(char *m_expression)
{
	if (m_expression == nullptr)
		return 0;

	int result = getIntFromAsci(m_expression[0]);
	int temp = 0;
	char operation = ' ';

	for (int i = 0; m_expression[i] != '\0'; i++)
	{
		if (i % 2 == 0)
		{
			temp = getIntFromAsci(m_expression[i]);
			if (operation == '*')
				result *= temp;
			else if (operation == '/')
				result /= temp;
		}
		else
			operation = m_expression[i];
	}
	return result;
}

int partitionMathExpression(char *m_expression)
{
	for (int i = 0; m_expression[i] != '\0'; i++)
	{
		
	}
	return 0;
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
	std::cout << "Unswer :" << calculateMathExpression(math_expression)<<std::endl;
	return 0;
}
