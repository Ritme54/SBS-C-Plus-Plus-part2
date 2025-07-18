#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String()
	{
		size = 0;
		pointer = nullptr;


	}

	void operator=(const char* word)
	{
		size = strlen(word) + 1;
		if (pointer == nullptr)
		{
			pointer = new char[size];
			for (int i = 0; i < size; i++)
			{
				pointer[i] = word[i];
			}

		}
		else
		{
			char* container = new char[size];
			for (int i = 0; i < size; i++)
			{
				container[i] = word[i];
			}
			delete[] pointer;
			pointer = container;
		}
	}


	const int& length()
	{

	}


	~String()
	{
		delete[] pointer;
	}

private:
	int size;
	char* pointer;


};



int main()
{
	//문자열의 길이를 반환하는 
	String message;
	message = "League of Legend";

	message = "Adidas";



}