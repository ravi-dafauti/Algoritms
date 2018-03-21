/*
Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. 
Such a representation is called Egyptial Fraction as it was used by ancient Egyptians.

Following are few examples:

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction, then recur for the remaining part.
For example, consider 6/14, we first find ceiling of 14/6, i.e., 3. So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42.
*/

#include<iostream>
using namespace std;

void printEgyptian(int nr, int dr)
{
	if (nr == 0 || dr == 0)
		return;
	if (nr >= dr)
	{
		//if numerator is divisible by denominator then its not a fraction
		if (nr%dr == 0)
		{
			cout << dr / nr;
			return;
		}
		else
		{
			cout << nr / dr << " + ";
			printEgyptian(nr%dr, dr);
		}
	}
	else if (nr < dr)
	{
		// if(denominator is divisible by numerator then simple division makes 1/n form
		if (dr%nr == 0)
		{
			cout << "1/" << dr / nr;
			return;
		}
		else
		{
			// find the celing and recur for the remaning fraction
			int dec = (dr / nr) + 1;
			cout << "1/" << dec << " + ";
			printEgyptian((nr*dec) - dr, dec*dr);
		}
	}
}
int main()
{
	int nr = 6, dr = 14;
	cout << "Egyptian Fraction Representation of "
		<< nr << "/" << dr << " is\n ";
	printEgyptian(nr, dr);
    return 0;
}

