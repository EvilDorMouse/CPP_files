﻿#include <iostream>

using namespace std;

void link()
{
    int x(10);
  
    int* y; //указатель
    y = &x;

    cout << "int x(10);\nint* y;\ny = &x;\n\n";
   
    cout << "----1----\n";
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 10

    cout << "----2----\ny++;\n";
    y = &x; x = 10;
    y++;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE24, значение: -858993460
    //----------------------------------------
    //адрес изменился на +4 байта или на +1 * размер типа int

    cout << "----3----\n++y;\n";
    y = &x; x = 10;
    ++y;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE24, значение: -858993460
    //----------------------------------------
    //адрес изменился на +4 байта или на +1 * размер типа int

    cout << "----4----\ny--;\n";
    y = &x; x = 10;
    y--;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE1C, значение: -858993460
    //----------------------------------------
    //адрес изменился на -4 байта или на -1 * размер типа int

    cout << "----5----\n--y;\n";
    y = &x; x = 10;
    --y;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE1C, значение: -858993460
    //----------------------------------------
    //адрес изменился на -4 байта или на -1 * размер типа int

    cout << "----6----\n*y++;\n";
    y = &x; x = 10;
    *y++;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE24, значение: -858993460
    //----------------------------------------
    //адрес изменился на +4 байта или на +1 * размер типа int (выполнение операции справа налево)

    cout << "----7----\n++ *y;\n";
    y = &x; x = 10;
    ++* y;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 11
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 11
    //----------------------------------------
    //изменилось значение переменной х, т.к. произошло обращение
    //к переменной по ссылке (выполнение операции справа налево)

    cout << "----8----\n*y--;\n";
    y = &x; x = 10;
    *y--;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE1C, значение: -858993460
    //----------------------------------------
    //адрес изменился на -4 байта или на -1 * размер типа int (выполнение операции справа налево)

    cout << "----9----\n-- *y;\n";
    y = &x; x = 10;
    --* y;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 9
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 9
    //----------------------------------------
    //изменилось значение переменной х, т.к. произошло обращение
    //к переменной по ссылке (выполнение операции справа налево)

    cout << "----10----\n(*y)++;\n";
    y = &x; x = 10;
    (*y)++;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 11
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 11
    //----------------------------------------
    //влияние скобок на порядок выполнения операций

    cout << "----11----\n++(*y);\n";
    y = &x; x = 10;
    ++(*y);
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 11
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 11
    //----------------------------------------
    //влияние скобок на порядок выполнения операций

    cout << "----12----\n(*y)--;\n";
    y = &x; x = 10;
    (*y)--;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 9
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 9
    //----------------------------------------
    //влияние скобок на порядок выполнения операций

    cout << "----13----\n--(*y);\n";
    y = &x; x = 10;
    --(*y);
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 9
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 9
    //----------------------------------------
    //влияние скобок на порядок выполнения операций

    cout << "----14----\n*y += 1;\n";
    y = &x; x = 10;
    *y += 1;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 11
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 11
    //----------------------------------------
    //разыменование имеет больший приоритет, чем сложение

    cout << "----15----\n*y += 2;\n";
    y = &x; x = 10;
    *y += 2;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 12
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE20, значение: 12
    //----------------------------------------
    //разыменование имеет больший приоритет, чем сложение

    cout << "----16----\ny += 1;\n";
    y = &x; x = 10;
    y += 1;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE24, значение: -858993460
    //----------------------------------------
    //адрес изменился на +4 байта или на +1 * размер типа int

    cout << "----17----\ny += 2;\n";
    y = &x; x = 10;
    y += 2;
    cout << "adress x: " << &x << "x = " << x << "\n";
    //адрес: 004FFE20, значение: 10
    cout << "adress y: " << y << "x = " << *y << "\n";
    //адрес: 004FFE28, значение: -398402934
    //----------------------------------------
    //адрес изменился на +8 байт или на +2 * размер типа int

    cout << "----18----\ny = 2;\n";
    y = &x; x = 10;
    //y = 2;
    cout << "adress x: " << &x << "x = " << x << "\n";
    cout << "adress y: " << y << "x = " << *y << "\n";
    //код ошибки: 0×80070002
    //нельзя присвоить указателю числовое значение
    cout << "error\n";
}