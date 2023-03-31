#pragma once
class Exception
{
	int code;
	char* mess;

public:
	Exception(int c, char* m);
	~Exception();
	void Show();
};