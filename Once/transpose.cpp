int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
	int** my = new int* [cols];
	my[0] = new int[rows * cols];

	for (int i = 1; i < cols; i++)
		my[i] = my[i - 1] + rows;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
				my[j][i] = m[i][j];
		
	}

	return my;
}