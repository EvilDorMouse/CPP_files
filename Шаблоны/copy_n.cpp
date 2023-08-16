template <typename t, typename u>
void copy_n (t* mass1, u* mass2, int n)
{
    for(int i = 0; i < n; i++)
    mass1[i] = (t)mass2[i];
}