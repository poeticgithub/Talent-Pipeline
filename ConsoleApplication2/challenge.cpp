//Nujoma Halls


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printOut(string stringarr, int size, int count);

int main() {

	int toCheck = 0, count = 0;
	char first, second, c;
	string mystring, mysubstring, error;
	
	error = "ERROR";

	try {

		getline(cin, mystring);
		first = mystring[0];
		second = mystring[1];

		if (isdigit(first) && isdigit(second)){
			toCheck = stoi(mystring.substr(0, 2));
		}
		else if (toCheck == 0)
			throw error;//throws error if the user did not begin input with two digits

		mysubstring = mystring.substr(2, mystring.length()); //this substring is the letters following the two digits of the input string
		
	    int i = 0;
		while (i < mysubstring.length()){
			c = mysubstring[i];
			if (!islower(c))
				throw error; //throws error user had inputted an upper case string, digit, or symbol
			i++;
		}
	}//end of try block

	catch (string s){
		cin.clear();
		cout << s << endl;
		cin.ignore();
		return 0;
	} //end of catch block

	int k = 0;
	for (int i = 0; i < toCheck - 1; i++){
		for (int k = i + 1; k < toCheck; k++){
			if (mysubstring[i] == mysubstring[k]){
				count++; //increment count if letter repeats
			}
		}
	}

	printOut(mysubstring, toCheck, count);

	system("pause");
	return 0;
}

void printOut(string stringarr, int size, int count) //will print repeated letters only once
{
	for (int i = 0; i < size; i++)
	{
		int k;
		for (k = 0; k<i; k++)
			if (stringarr[i] == stringarr[k])
				break;
		if (i == k) 
			cout << stringarr[i] << " " << count << endl;
	}
}