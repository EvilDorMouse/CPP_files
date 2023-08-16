#include <algorithm> // std::swap
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String 
{
	//конструктор 1
	String(const char* str = "")
	{
		size = strlen(str);

		this->str = new char[size + 1];

		strcpy(this->str,str);
	}

	//конструктор 2
	String(size_t n, char c)
	{
		size = n;
		str = new char[size + 1];

		for (int i = 0; i < n; i++)
			str[i] = c;
	}

	//деструктор
	~String()
	{
		delete[] str;
	}

	//конструктор копирования
	String(const String &other)
    	{
        	size = other.size;
        
        	str = new char[size + 1];
        
        	for(int i = 0; i < size + 1; i++)
            		str[i] = other.str[i];
    	}

	//оператор присваивания
	String &operator=(const String &other)
    	{
        	if (this != &other)
        	{
            		size = other.size;
        
            		delete []str;
            		str = new char [size + 1];
        
            		for (int i = 0; i < size + 1; i++)
            			str[i] = other.str[i];
        	}
        
        	return *this; 
    	}

	//обавляет копию строки-аргумента в конец текущей строки
	void append(String& other)
	{
		size_t ns = size + other.size + 1;
		char* trash = new char[ns];
		
		for (int i = 0; i < size; i++)
			trash[i] = str[i];

		for (int i = 0; i < other.size; i++)
			trash[i+size] = other.str[i];

		trash[ns - 1] = '\0';

		delete[] str;
		str = new char[ns];
		size = ns - 1;

		for(int i = 0; i < ns; i++)
			str[i] = trash[i];

		delete[] trash;
	}

	size_t size;
	char *str;





        String(char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
			

		this->size = i;
		this->str = new char[size + 1];

		for (int i = 0; i < size + 1; i++)
			this->str[i] = str[i];
	}
  
    
    
    	struct StringT
    	{
		StringT(char* str, int poss)
		{
			int i = 0;
			while (str[i] != '\0')
				{
					i++;
				}


			this->sizet = i;
			this->strt = new char[sizet + 1];

			for (int i = 0; i < sizet + 1; i++)
				this->strt[i] = str[i];

			pos = poss;
		}
        
        	StringT (char* str = 0)
		{
			int i = 0;
			while (str[i] != '\0')
			{
				i++;
			}


			this->sizet = i;
			this->strt = new char[sizet + 1];

			for (int i = 0; i < sizet + 1; i++)
				this->strt[i] = str[i];

			pos = 0;
		}

		~StringT()
		{
			delete[] strt;
		}

		String const operator[](int j) const
		{
			int n = j - pos;
			char* copy = new char[n + 1];

			for (int i = 0; i < n; i++)
				copy[i] = strt[i];

			copy[n] = '\0';

			StringT tt (copy);

			delete[] copy;

			return String(tt.strt);
		}

		size_t sizet;
		char* strt;
		int pos;
	};
    
    

    
    	StringT operator[](int i) const
	{
		size_t n = size - i;
		char* copy1 = new char[n];

		for (int h = i; h < size; h++)
			copy1[h - i] = str[h];

		StringT tt(copy1, i);

		delete []copy1;

		return tt;
	}
};