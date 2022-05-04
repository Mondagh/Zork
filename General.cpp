#include "pch.h"
#include "General.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;



 void Tokenize(const string & line, vector<string>& arguments)
 {
	 const char* str = line.c_str();

	 do
	 {
		 const char *begin = str;

		 while (*str != ' ' && *str)
			 str++;

		 arguments.push_back(string(begin, str));
	 } while (0 != *str++);
 }

 char ToUpper(string & argument)
 {
	// cout << argument;
	 char upper='a';

	// upper += ::toupper(*cstr);
	 const char* str = argument.c_str();

	 do
	 {
		 const char *begin = str;

		 while (*str != ' ' && *str) {
			cout << ::toupper(*str) + "\n";
			 str++;
		 }
			 

		 
	 } while (0 != *str++);
	 cout << upper + "\n";
	
	 

	return upper;
 }

 bool Compare(const string& a, const string& b)
 {
	 return _stricmp(a.c_str(), b.c_str()) == 0;
 }


