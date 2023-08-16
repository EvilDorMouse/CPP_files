template <typename type, size_t t>
size_t array_size(type (&a)[t])
{
    return t;
}