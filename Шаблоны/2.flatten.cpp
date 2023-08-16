template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
    for(int i = 0; i < array.size(); i++)
    out << array[i] << " ";
}

template <typename T>
void flatten(const Array< Array<T> >& array, std::ostream& out)
{
    for(int i = 0; i < array.size(); i++)
    flatten(array[i], out);
}