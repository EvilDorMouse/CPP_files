void rotate(int a[], unsigned size, int shift)
{
    int b = 0;
    if (shift > size)
    {
        shift = shift % size;
    }

    for (int j = 0; j < size - shift; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            b = a[i + 1];
            a[i + 1] = a[0];
            a[0] = b;
        }
    }
}