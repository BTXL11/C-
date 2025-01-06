#include "solution.h"

int solution::add(int a, int b)
{
    return a + b;
}
bool solution::isValid(std::string s)
{
	bool test;
	std::string s1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[j] == ')')
				{
					s1 = s.substr(i + 1, j - i - 1);
					test = isValid(s1);
					if (test)
					{
						i += s1.length();
						return true;
					}
					else
					{
						return false;
					}
				}
				else if (j == s.length() - 1)
				{
					return false;
				}
			}

		}
		if (s[i] == '[')
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[j] == ']')
				{
					s1 = s.substr(i + 1, j - i - 1);
					test = isValid(s1);
					if (test)
					{
						i += s1.length();
						return true;
					}
					else
					{
						return false;
					}
				}
				else if (j == s.length() - 1)
				{
					return false;
				}

			}
		}
		if (s[i] == '{')
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[j] == '}')
				{
					s1 = s.substr(i + 1, j - i - 1);
					test = isValid(s1);
					if (test)
					{
						i += s1.length();
						return true;
					}
					else
					{
						return false;
					}
				}
				else if (j == s.length() - 1)
				{
					return false;
				}
			}

		}

	}

}