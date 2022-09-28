#include <iostream>

using namespace std;

#include "List.h"

// linear search for the first occurrence of character c in pchs of N characters
int FindFirst(char* pchs, int N, char c)
{
	for (int i = 0; i < N; i++) 
		if (pchs[i] = c) 
			return i;
	return -1;
}
void testFindFirst(int N)
{
	char* pchs = new char[N];
	for (int i = 0; i < N; i++) pchs[i] = 'a' + rand() % 26;
	// search for the first occurrence of character c
	char c = 'j';
	cout << "The first occurrence of " << c << " is at "
		<< FindFirst(pchs, N, c) << endl;
	// complexity of the search
	cout << "The complexity of the search is O(N)" << endl;
	delete[] pchs;
}

void compareSearch(List<int>* ilist, int key)
{
	// position of key in the list
	int position = -1;
	// algorithm 1: linear search for the given key using get(int p)
	for (int p = 0; p < ilist->size(); p++)
		if (ilist->get(p) == key) {
			position = p;
			break;
		}
	cout << "Position of " << key << " = " << position << endl;
	cout << "The complexity of the search is O(N squared), where N = ilist->size()"
		<< endl;
	// algorithm 2: linear search for the given key using get_next()
	position = -1;
	/* (1) code to perform the search */
	ilist->setp_first();
	for (int p = 0; p < ilist->size(); p++) {
		if (ilist->get_next() == key) {
			position = p;
			break;
		}
	}
	/* (2) code to print the position & complexity */
	cout << "Position of " << key << " = " << position << endl;
	cout << "The time complexity of this algorithm is O(N), where N = ilist->size()" << endl;
	// algorithm 3: binary search for the given key
	position = -1;
	/* (3) code to perform the binary search */
	int first = 0;
	int last = ilist->size() - 1;
	do
	{
		int middle = (first + last) / 2;
		int middleValue = ilist->get(middle);
		if (middleValue == key) {
			position = middle;
			break;
		}
		else if (middleValue > key) {
			last = middle - 1;
		}
		else 
			first = middle + 1;
	} while (first < last);
	/* (4) code to print the position & complexity */
	cout << "Position of " << key << " = " << position << endl;
	cout << "The time complexity of this algorithm is O(N*log(N)) where N = ilist->size()" << endl;
}


int main1()
{
	// a linked list with 1000 sorted integers
	List<int> ilist;
	for (int i = 1; i <= 1000; i++)
		ilist.insert_end(2 * i - 1);
	compareSearch(&ilist, 1997);
	return 0;
}

template<typename T>
int binarySearch(T* v, int first, int last, T key)
{
	// base case - not found
	if (first > last) return -1;
	// recursive case
	int mid = (first + last) / 2;
	if (v[mid] == key)
		return mid;
	else if (key < v[mid])
		return binarySearch(v, first, mid - 1, key);
	else
		return binarySearch(v, mid + 1, last, key);
}

int main2()
{
	int N, key;
	cout << "Array size N = "; cin >> N;
	cout << "key value to be searched = "; cin >> key;
	int* pi = NULL;
	if (N <= 0 || (pi = new int[N]) == NULL) {
		cout << "Array allocation fails. Exit.";
		return 1;
	}
	for (int i = 0; i < N; i++)
		pi[i] = rand() % 1000;
	cout << "key value is found at " << binarySearch(pi, 0, N - 1, key) << endl;
	delete[] pi;
	cout << "I disapprove of this design because the array is not sorted and binary search required the array to be sorted" << endl;
	return 0;
}

template<typename T>
int binarySearch_(T* v, int first, int last, T key) {
	if (first > last) return -1; // base case
	int mid = (first + last) / 2;
	if (v[mid] == key) {
		return mid;
	}
	else if (key > v[mid]) {
		return binarySearch_(v, first, mid - 1, key);
	}
	else 
		return binarySearch_(v, mid + 1, last, key);
}

int main()
{
	char* alphabet = new char[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = 'z' - i;
	cout << binarySearch_(alphabet, 0, 25, 'b') << endl;

	cout << "The search using binarySearch fails because the array is sorted in reverse order ";
	cout << "where left is greater than right, the current binary search algorithm relies on ";
	cout << "an ascending order in the array as it assumes left values are less than right values" << endl;

	delete[] alphabet;
	return 0;
}