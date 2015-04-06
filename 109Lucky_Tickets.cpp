#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

void numAdding(long long level, long long sum, long long max, vector<long long> * values)
{
	if(level == 0)
	{
		for(long long i = 0; i < max; i++)
		{
			long long sum2 = sum + i;
				values->at(sum2)++;

		}
	}
	else
	{
		for(long long i = 0; i < max; i++)
		{
			numAdding(level - 1, sum + i, max, values);
		}
	}
	
}

void tickets(long long length, long long base, vector<long long> * output)
{
	bool extraValue = length % 2 == 1;
	if(extraValue)
		length--;
	
	long long maxValue = (length / 2) * (base - 1);
	long long count = 0;

	if(length != 0)
	{
		vector<long long> numValues(maxValue + 1, 0);

		numAdding(length / 2 - 1, 0, base, &numValues);

		for(long long i = 0; i < numValues.size(); i++)
		{
			count += numValues.at(i) * numValues.at(i);
			//cout << numValues.at(i) << endl;
		}


		
		if(extraValue)
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
	long long numInputs;

	vector<long long> output;
	cout << "input data:" << endl;
	
	cin >> numInputs;

	for(long long i = 0; i < numInputs; i++)
	{
		long long length;
		long long base;
		cin >> length;
		cin >> base;

		tickets(length, base, &output);
	}

	cout << endl << "answer:" << endl;

	for(vector<long long>::iterator it = output.begin(); it != output.end(); ++it)
	{
		cout<< *it << ' ';
	}
	cout << endl;
}
