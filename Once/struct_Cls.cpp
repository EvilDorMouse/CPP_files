/*
struct Cls 
{
    Cls(char c, double d, int i);

    private:
    char c;
    double d;
    int i;
 };
 */

// Эта функция должна предоставить доступ к полю c объекта cls.
// доступ предоставляется на чтение и запись.
 char& get_c(Cls& cls)
 {
     return *(char*)(&cls);
 }

// Эта функция должна предоставить доступ к полю d объекта cls.
// доступ предоставляется на чтение и запись.
 double& get_d(Cls& cls)
 {
     return  *(double*)((char*)(&cls) + sizeof(char*));
 }

// Эта функция должна предоставить доступ к полю i объекта cls.
// доступ предоставляется на чтение и запись.
 int& get_i(Cls& cls)
 {
     return *(int*)((char*)&cls + sizeof(char*) + sizeof(double*));
 }



