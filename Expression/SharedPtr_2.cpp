struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{

    explicit SharedPtr(Expression* ptr = 0) 
        : ptr_(ptr)
    {
        if (ptr_)
            MyCount = new int(1);
    }

    SharedPtr(const SharedPtr& other)
        : ptr_(other.ptr_), MyCount(other.MyCount)
    {
        if (ptr_)
            (*MyCount)++;
    }

    ~SharedPtr()
    {
        if (ptr_)
        {
            if ((*MyCount) - 1 == 0)
            {
                delete ptr_;
                delete MyCount;

                //cout << "~SharedPtr()" << endl << endl;
            }
            else
                (*MyCount)--;
        }
    }    

    SharedPtr& operator= (const SharedPtr& other)
    {
        if (this != &other)
        {
            if (MyCount != 0)
                if ((*MyCount) - 1 == 0)
                {
                    delete ptr_;
                    delete MyCount;
                }
                else if (ptr_ != other.ptr_)
                    (*MyCount)--;

            MyCount = other.MyCount;

            if (other.MyCount != 0 && ptr_ != other.ptr_)
                (*MyCount)++;

            ptr_ = other.ptr_;
        }

        return *this;
    }



    void reset(Expression* ptr = 0)
    {
        if (ptr == NULL && MyCount != NULL)
        {
            if (*MyCount == 0)
            {
                delete MyCount;
                MyCount = 0;
            }
            else if ((*MyCount) == 1)
            {
                delete ptr_;
                delete MyCount;

                MyCount = 0;
            }
            else
            {
                (*MyCount)--;
                MyCount = 0;
            }
        }
        else
        {
            if (MyCount == NULL)
            {
                MyCount = new int(1);
            }
            else if (*MyCount == 0)
            {
                delete MyCount;
                MyCount = new int(1);
            }
            else if ((*MyCount) == 1)
            {
                delete ptr_;
                delete MyCount;

                MyCount = new int(1);
            }
            else
            {
                (*MyCount)--;
                MyCount = new int(1);
            }
        }
        
        ptr_ = ptr;
    }

    

    Expression* get() const
    {
        return ptr_;
    }

    Expression& operator*() const
    {
        return *ptr_;
    }

    Expression* operator->() const
    {
        return ptr_;
    }

private:

    Expression* ptr_ = 0;
    int* MyCount = 0;
};