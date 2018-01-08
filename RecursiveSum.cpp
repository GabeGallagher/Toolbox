/* Author Gabriel B. Gallagher 
 * 
 * class is a container for several methods used for finding the sum of numbers within given data
 * structures. 
 * 
 * VectorSum is modified from code that can be found at 
 * http://www.geeksforgeeks.org/sum-array-elements-using-recursion
 *
 * The function takes an int vector and an int number of elements (n) as input and returns the sum 
 * of the elements up to n. vec.size() will give sum of all elements in the vector
 */

#include "RecursiveSum.h"

RecursiveSum::RecursiveSum()
{
}

int RecursiveSum::VectorSum(std::vector<int> vec, int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return VectorSum(vec, n - 1) + vec.at(n - 1);
}

RecursiveSum::~RecursiveSum()
{
}
