int strstr(const char* text, const char* pattern)
{
	int i = 0, j = 0, s = 0;

	while (pattern[i] != '\0')
	{
		i++;
	}
    
    if (i == 0)
		return 0;

	while (text[j] != '\0')
	{
		j++;
	}

	for (int k = 0; k < j - i + 1; k++)
	{
		for (int m = 0; m < i; m++)
		{
			if (text[k + m] == pattern[m])
			{
				s++;
			}
		}
	

		if (s == i)
		{
            		return k;
		}

		s = 0;
	}

	return -1;
}

