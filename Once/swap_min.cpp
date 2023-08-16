void swap_min(int* m[], unsigned rows, unsigned cols)
{
    int* my;
    int* mini = &m[0][0];
    int myrow = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (*mini > m[i][j])
            {
                mini = &m[i][j];
                myrow = i;
            }

    my = m[myrow];
    m[myrow] = m[0];
    m[0] = my;
}