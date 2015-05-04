/*
  Solution for the problem at http://www.codeabbey.com/index/task_view/lucky-tickets

  Determine how many tiket numbers of a given length and base are 'lucky'

  A lucky ticket is one where the first half of the digits and the last half of the digits
  add up to the same number.

  If the length of the number is odd, the middle digit is ignored
 */


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/*
  Function: numAdding
  Purpose: Determine the number of different combinations that can be added
           up to each number from 0 to values.size()
  Input:
    level: the number of digits left to process (start at length of ticket / 2)
	sum: the sum of the digits currently processed
	max: the base of the values proecessed; the maximum value of each digit
  Output:
    values: stores the number of times each value can be added to
 */
void numAdding(long long level, long long sum, int max, vector<long long> * values)
{
	//if all digits have been processed
	if(level == 0)
	{
		//for each number that the digit could be, add it to sum and put it in values
		for(int i = 0; i < max; i++)
		{
			long long sum2 = sum + i;
			values->at(sum2)++; //iterate the count for this value

		}
	}
	else
	{
		//for each number that the digit could be, add it to sum and call this function again
		for(int i = 0; i < max; i++)
		{
			numAdding(level - 1, sum + i, max, values);
		}
	}
	
}

/*
  Function: tickets
  Purpose: determine the number of lucky tickets of a given length and base
  Input:
    length: length of the ticket
	base: base of the ticket number
  Output:
    output: output is pushed to this vector
 */
void tickets(long long length, int base, vector<long long> * output)
{
	//extraVale: true if length is odd, false otherwise
	bool extraValue = length % 2 == 1;
	if(extraValue)
		length--;

	
	long long maxValue = (length / 2) * (base - 1);
	long long count = 0;

	if(length != 0)
	{
		//stores the number of times each value is found
		vector<long long> numValues(maxValue + 1, 0);

		numAdding(length / 2 - 1, 0, base, &numValues);

		//determine the total count of possible lucky tickets
		for(long long i = 0; i < numValues.size(); i++)
		{
			count += numValues.at(i) * numValues.at(i);
		}


		
		if(extraValue) //if number is odd, multiply by base to simulate extra digit
			output->push_back(count * base);
		else
			output->push_back(count);
	}
	else
	{
		output->push_back(base);
	}
}

int main()
{
	//number of user inputs
	int numInputs;

	//vector containing output
	vector<long long> output;
	cout << "input data:" << endl;
	
	cin >> numInputs;

	//read input
	for(long long i = 0; i < numInputs; i++)
	{
		long long length;
		long long base;
		cin >> length;
		cin >> base;

		tickets(length, base, &output);
	}

	cout << endl << "answer:" << endl;

	//output results
	for(vector<long long>::iterator it = output.begin(); it != output.end(); ++it)
	{
		cout<< *it << ' ';
	}
	cout << endl;
}
