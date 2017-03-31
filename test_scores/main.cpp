#include <iostream>
#include <string>
#include <limits>
using namespace std;

int getInt(string);
double getDouble(string);
string getString(string);
void sort(double*, string*, int);
double avg(double*, int);

int main()
{
	int student_count = getInt("How many students?");

	double *scores = new double[student_count];
	string *names = new string[student_count];

	for (int i = 0; i < student_count; i++)
	{
		cout << "Student " << i + 1 << endl;
		*(names + i) = getString("Name:");
		*(scores + i) = getDouble("Score:");
	}

	sort(scores, names, student_count);

	for (int i = 0; i < student_count; i++)
	{
		cout << "Student " << i + 1 << ": "
			<< *(names + i) << endl
			<< "Score: " << *(scores + i) << endl;
	}

	cout << "Average score: " << avg(scores, student_count) << endl;

	delete[] names;
	delete[] scores;

	system("pause");
}

void sort(double *scores, string *names, int size)
{
	bool done = false;
	for (int i = size-1; !done; i--)
	{
		done = true;
		for (int k = 0; k < i; k++)
		{
			if (*(scores + k) > *(scores + k + 1))
			{
				double tempScore = *(scores + k);
				string tempName = *(names + k);
				*(scores + k) = *(scores + k + 1);
				*(names + k) = *(names + k + 1);
				*(scores + k + 1) = tempScore;
				*(names + k + 1) = tempName;
				done = false;
			}
		}
	}
}

double avg(double* scores, int size)
{
	double avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += *(scores + i);
	}
	return avg / size;
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
			cout << "Invalid input\n>> ";
		}
		else
		{
			return input;
		}
	}
}

double getDouble(string prompt)
{
	cout << prompt << "\n>> ";
	double input;
	while (true)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n>> ";
		}
		else
		{
			return input;
		}
	}
}

string getString(string prompt)
{
	cout << prompt << "\n>> ";
	string input;
	cin >> input;
	return input;
}
