/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  ================================================
*
*	Sorting Algorithm Strategy API Test file
*
*/

#include <iostream>

#include "sorting_algorithms.hpp"

template <class T>
void print(T Array[], unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		std::cout << Array[i] << " ";
	}
	std::cout << "\n";
}

template <class T>
void shuffle(T Array[], unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		std::swap(Array[i], Array[(Array[i] % size)]);
	}
}

template <class T>
T max_element(T Array[], unsigned size) {
	T max = Array[0];
	for (unsigned i = 1; i < size; ++i) {
		if (max < Array[i])
			max = Array[i];
	}
	return max;
}

int main() {


	int arr[5] = {50, 4, 31, 222, 11 };
	
	// Insertion sort
	std::cout << "Insertion sort:\n";
	sorting_algorithms::insertion_sort<int> insertion;
	insertion(arr, 5);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Bubble sort
	std::cout << "Bubble sort:\n";
	sorting_algorithms::bubble_sort<int> bubble;
	bubble(arr, 5);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Min sort
	std::cout << "Min sort:\n";
	sorting_algorithms::min_sort<int> min_sort;
	min_sort(arr, 5);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Counting sort
	std::cout << "Counting sort:\n";
	sorting_algorithms::counting_sort<int> counting_sort;
	int max = max_element(arr, 5);
	counting_sort(arr, 5, max);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Merge sort
	std::cout << "Merge sort:\n";
	sorting_algorithms::merge_sort<int> merge_sort;
	merge_sort(arr, 0, 4);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Quicksort
	std::cout << "Quicksort:\n";
	sorting_algorithms::quicksort<int> quicksort;
	quicksort(arr, 0, 4);
	print(arr, 5);

	shuffle(arr, 5);
	std::cout << "\n\n";

	// Heapsort
	std::cout << "Heapsort:\n";
	sorting_algorithms::heapsort<int> heapsort;
	heapsort(arr, 5);
	print(arr, 5);

	std::cout << "\n\n";

	return 0;
}