#include <iostream>

 struct Foo
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char* msg) : msg(msg) { }
private:
     const char* msg;
    
};

void foo_says(const Foo& foo) { foo.say(); }

 struct foo_ch : public Foo
 {
     foo_ch(const char* msg) : Foo(msg) {}
 };


foo_ch get_foo(const char* msg)
{
    foo_ch ch(msg);

    return ch;
}

int main()
{
    foo_says(get_foo("Hello!"));
}