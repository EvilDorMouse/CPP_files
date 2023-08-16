/*
template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};
*/





template <class t, class C>
    t minimum(Array<t> & arr, C comp)
{
    t ch = arr[0];
    for(int i = 0; i < arr.size(); i++)
        if(comp(arr[i], ch))
           ch = arr[i];
        
                      
    return ch;
}