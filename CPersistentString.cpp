#include <fstream>
#include <cstring>
#include "CPersistentString.h"

using namespace std;

	CPersistentString::CPersistentString()
	{
		setContent(load());
		setLength(calculateLength());
	}

	CPersistentString::~CPersistentString()
	{

	}

	string CPersistentString::load()
	{
		int count = 0;
		ifstream istream("input.txt"); // input stream
		if (istream.is_open())
		{
			cout << "Reading file." << endl;
			while (!istream.eof())
			{
				istream >> content;
				count++;
			}
		}
		else
		{
			cout << "File could not be opened." << endl;
		}
		istream.close();
		return content;
	}

	void CPersistentString::setContent(string _content)
	{
		content = _content;
	}

	string CPersistentString::getContent()
	{
		return content;
	}

	int CPersistentString::calculateLength()
	{
		int i;
		for (i = 0; content[i] != '\0'; i++)
		{
		}
		return i;
	}

	void CPersistentString::setLength(int _length)
	{
		length = _length;
	}

	int CPersistentString::getLength()
	{
		return length;
	}

	bool CPersistentString::isPalindrome()
	{
		for (int i = 0; i < length; i++) {
			if (content[i] != content[length - 1 - i])
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}

	void CPersistentString::persist()
	{
		ofstream ostream("output.txt");
		if (ostream.is_open())
		{
			cout << "Writing to file." << endl;
			ostream << "The string '" << content << "' has " << length << " characters, and is";

			if (!isPalindrome())
			{
				ostream << " not";
			}
			ostream << " a palindrome." << endl;
			ostream.close();
		}
		else
		{
			cout << "File could not be closed." << endl;
		}
	}
