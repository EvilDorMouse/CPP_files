template <typename T1, typename T2>
struct SameType
{
    static const bool value = false;
};

template <typename T1>
struct SameType<T1, T1>
{
    static const bool value = true;
};