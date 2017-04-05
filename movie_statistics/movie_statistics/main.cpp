#include <iostream>
#include <string>
#include <limits>
using namespace std;

int getInt(string);
double avg(int*, int);
int median(int*, int);
int mode(int*, int);
void sort(int*, int);

int main()
{
	int size = getInt("How many students are being surveyed?");

	int *survey = new int[size];

	for (int i = 0; i < size; i++)
	{
		survey[i] = getInt("How many movies did this student watch?");
	}

	for (int i = 0; i < size; i++)
	{
		cout << survey[i] << ", ";
	}
	cout << endl;

	sort(survey, size);

	for (int i = 0; i < size; i++)
	{
		cout << survey[i] << ", ";
	}
	cout << endl;

	cout << "The average is: " << avg(survey, size) << endl;
	cout << "The median is: " << median(survey, size) << endl;
	cout << "The mode is: " << mode(survey, size) << endl;

	system("pause");
}

double avg(int *survey, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += survey[i];
	}
	return sum / size;
}

int median(int *survey, int size)
{
	return survey[size / 2];
}

int mode(int* survey, int size)
{
	int currentGroup, currentGroupSize, largestGroup, largestGroupSize;
	currentGroup = largestGroup = survey[0];
	currentGroupSize = largestGroupSize = 1;

	for (int i = 0; i < size; i++)
	{
		if (survey[i] == currentGroup)
		{
			currentGroupSize++;
		}
		else
		{
			if (currentGroupSize > largestGroupSize)
			{
				largestGroup = currentGroup;
				largestGroupSize = currentGroupSize;
			}
			currentGroup = survey[i];
			currentGroupSize = 1;
		}
	}
	return largestGroup;
}

void sort(int* data, int size)
{
	bool sorted = false;
	for (int i = size-1; !sorted; i--)
	{
		sorted = true;
		for (int k = 0; k < i; k++)
		{
			if (data[k] > data[k + 1])
			{
				int temp = data[k];
				data[k] = data[k + 1];
				data[k + 1] = temp;
				sorted = false;
			}
		}
	}
}

int getInt(string prompt)
{
	cout << prompt << "\n>> ";
	int input;
	while (true)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.\n>> ";
		}
		else
		{
			break;
		}
	}
	return input;
}
