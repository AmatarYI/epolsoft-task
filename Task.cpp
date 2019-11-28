#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> newArray;

	const int lenght = 9;
	string binaryString;
	string wordsArray[lenght];
	char temp;
	bool flag = true;

	cout << "  Let's enter our string array.\n";
	for (int i = 0; i < lenght; i++)
	{
		cout <<"  " << i + 1 << ") ";
		cin >> wordsArray[i];
	}

	// using try/catch to control the string binary
	try
	{
		cout << "\n  Enter a string consisting of 0's and/or 1's: " ;
		cin >> binaryString;
		// fill or cut string with ones(1) in case of user mistakes
		binaryString.resize(lenght, '1');

		for (int i = 0; i < lenght; i++)
		{
			// using temp to 1 character reading
			temp = binaryString[i];
			// subtraction ASCII value for zero from temp ASCII
			int tempInt = temp - '0';
			if (temp < 48 )
			{
				// clearing newArray vector due to possible recorded values
				newArray.clear();
				throw 404;
			}
			else if (temp > 49)
			{
				newArray.clear();
				throw 404;
			}
			else if (tempInt == 1)
			{
				newArray.push_back(wordsArray[i]);
			}
		}
	}
	catch (int)
	{
		while (flag)
		{
			cout << "\n  Enter only binary(0 or 1) string:  ";
			cin >> binaryString;
			binaryString.resize(lenght, '1');

			char temp; 
			for (int i = 0; i < lenght; i++)
			{
				temp = binaryString[i];
				int tempInt = temp - '0'; 
				if (temp < 48)
				{
					cout << "\n  Here we go again... Enter binary(0 or 1) string: ";
					cin >> binaryString;

					binaryString.resize(lenght, '1');
					newArray.clear();
					// set i to zero to start the cycle from the beginning
					i = 0;
				}

				else if (temp > 49)
				{
					cout << "\n  Here we go again... Enter binary(0 or 1) string: ";
					cin >> binaryString;

					binaryString.resize(lenght, '1');
					newArray.clear();
					i = - 1;
				}
				else if (tempInt == 1)
				{
					newArray.push_back(wordsArray[i]);
				}
			}
			// stop working with the cycle if everything is fine
			flag = false;
		}
	}

	cout << "\n  Our grand array: \n";
	unsigned int vector_size = newArray.size();
	for (int i = 0; i < vector_size; i++)
	{
		cout << i <<") "<<newArray[i] << endl;
	}
}
