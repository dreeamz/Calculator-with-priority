#include <iostream>
#include <stack>

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
int converCharToInt(char sym)
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

int calculate(int num1, int num2, char operation)
{
	int result = 0;
	switch (operation)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		break;
	}
	return result;
}
bool validOperation(char operation)
{
	if (operation == '*' || operation == '/' || operation == '-' || operation == '+')
		return true;
	return false;
}

int getExpressionInBracketsLength(char *m_expression, int l, int r)
{
	int length = 0;
	int brackets_count = 1;
	int i = l;
	while (brackets_count > 0 && m_expression[i] != '\0')
	{
		if (m_expression[i] == '(')
			brackets_count++;
		else if (m_expression[i] == ')')
			brackets_count--;
		i++;
		length ++;
	}
	return length -1;
}

int calculateExpression(char *m_expression, int l, int r)
{
	if (l == r)
		return converCharToInt(m_expression[l]);

	int result = 0, num = 0, brackets_count = 0, num_len = 0, exp_in_brack_length = 0;
	char operation = ' ';

	for (int i = l; i <= r; i++)
	{
		switch (m_expression[i])
		{
		case '(':
			brackets_count++;
			num_len = 0;
			exp_in_brack_length = getExpressionInBracketsLength(m_expression, i + 1, r);
			break;
		case ')':
			brackets_count--;
			num_len = 0;
			break;
		case '+':
			num_len = 0;
			if (!brackets_count)
				return result + calculateExpression(m_expression, i + 1, r);
		case '-':
			num_len = 0;
			if (!brackets_count)
				return result - calculateExpression(m_expression, i + 1, r);
		case '*':
			operation = '*';
			num_len = 0;
			break;
		case '/':
			operation = '/';
			num_len = 0;
			break;
		default:
			if (brackets_count)
			{
				num = calculateExpression(m_expression, i, i + exp_in_brack_length - 1);
				result = calculate(result, num, operation);
				i+=exp_in_brack_length;
				brackets_count = 0;
			}
			else
			{
				num_len++;
				if (num_len == 1)
					num = converCharToInt(m_expression[i]);						
				else if (num_len > 1)
					num = num * 10 + converCharToInt(m_expression[i]);

				if (!validOperation(operation))
					result = num;
				else
					result = calculate(result, num, operation);
			}
		}
	}
	return result;
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
	int result = calculateExpression(math_expression, 0, size - 1);
	std::cout << "Answer :" << result << std::endl;

	return 0;
}
