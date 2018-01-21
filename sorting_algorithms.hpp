/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  ================================================
*
*	Sorting Algorithm Strategy API Definition
*
*/

// Multiple inclusion guards
#ifndef SORTING_ALGOS_HPP
#define SORTING_ALGOS_HPP

namespace sorting {
	namespace algorithms {

		// Counting sort
		template <class T>
		class counting_sort {
		public:
			void operator()(T Array[], unsigned size, T max_elem) {

				T * temp = new T[max_elem + 1];
				T * result = new T[size];

				for (unsigned i = 0; i <= max_elem; i++) {
					temp[i] = 0;
				}

				for (unsigned i = 0; i < size; i++) {
					temp[Array[i]]++;
					result[i] = 0;
				}

				for (unsigned i = 1; i <= max_elem; i++) {
					temp[i] += temp[i - 1];
				}

				for (unsigned i = 0; i < size; i++) {
					result[--temp[Array[i]]] = Array[i];
				}
				
				for (unsigned i = 0; i < size; i++) {
					Array[i] = result[i];
				}

				delete[] temp;
				delete[] result;
			}
		};

		// Bubble sort
		template <class T>
		class bubble_sort {
		public:
			void operator()(T Array[], unsigned size) { // 5, 4, 3, 2, 1, 0
				if (size == 0 || size == 1) return;
				if (size == 2) {
					if (Array[0] > Array[1]) {
						T temp = Array[0];
						Array[0] = Array[1];
						Array[1] = temp;
					}
					return;
				}
				for (unsigned i = 0; i < size; i++) 
					for (unsigned j = i + 1; j < size; j++) 
						if (Array[i] > Array[j])
							std::swap(Array[i], Array[j]);
			}
		};

		// Min sort
		template <class T>
		class min_sort {
		public:
			void operator()(T Array[], unsigned size) { 
				if (size == 0 || size == 1) return;
				if (size == 2) {
					if (Array[0] > Array[1]) {
						T temp = Array[0];
						Array[0] = Array[1];
						Array[1] = temp;
					}
					return;
				}

				for (unsigned i = 0; i < size; i++) {
					int min = Array[i];
					int min_index = i;
					for (unsigned j = i + 1; j < size; j++) {
						if (min > Array[j]) {
							min = Array[j];
							min_index = j;
						}
					}
					T temp = Array[i];
					Array[i] = Array[min_index];
					Array[min_index] = temp;
				}
			}
		};

		
		// Insertion sort
		template <class T>
		class insertion_sort {
		public:
			void operator()(T Array[], unsigned size) { // 5, 4, 3, 2, 1, 0
				if (size == 0 || size == 1) return;
				if (size == 2) {
					if (Array[0] > Array[1]) {
						T temp = Array[0];
						Array[0] = Array[1];
						Array[1] = temp;
					}
					return;
				}
				for (unsigned i = 1; i < size; i++) {
					T key = Array[i];
					int j = i - 1;
					while (j >= 0 && key < Array[j]) {
						Array[j + 1] = Array[j];
						j--;
					}
					Array[j + 1] = key;
				}
			}
		};

		// Merge sort
		template <class T>
		class merge_sort {
		public:

			void operator()(T Array[], int start, int end) {
				merge_sort_(Array, start, end);
			}

		private:

			void merge_sort_(T Array[], int start, int end) {
				if (start < end) {
					int mid = start + (end - start) / 2;

					merge_sort_(Array, start, mid);
					merge_sort_(Array, mid + 1, end);

					merge(Array, start, mid, end);
				}
			}
			void merge(T arr[], int low, int mid, int high) {

				int * temp = new int[high - low + 1];

				// i left, j right
				int i = low, j = mid + 1;

				// k temp
				int k = 0;

				while (i <= mid && j <= high) {
					if (arr[i] <= arr[j])
						temp[k++] = arr[i++];
					else
						temp[k++] = arr[j++];
				}

				//rest elements of left-half
				while (i <= mid)
					temp[k++] = arr[i++];

				//rest elements of right-half
				while (j <= high)
					temp[k++] = arr[j++];

				//copy the mergered temporary array to the original array
				for (k = 0, i = low; i <= high; ++i, ++k)
					arr[i] = temp[k];

				delete[] temp;
			}
		};

		// Quicksort
		template <class T>
		class quicksort {
		public:
			void operator()(T Array[], int begin, int end) {
				quicksort_(Array, begin, end);
			}
		private:
			void quicksort_(T Array[], int begin, int end) {
				if (begin < end) {
					int mid = partition(Array, begin, end);
					quicksort_(Array, begin, mid - 1);
					quicksort_(Array, mid + 1, end);
				}
			}

			int partition(T Array[], int begin, int end) {
				T x = Array[end];
				int i = begin - 1;
				for (unsigned j = begin; j < end; j++) {
					if (Array[j] <= x) {
						i++;
						std::swap(Array[j], Array[i]);
					}
				}
				std::swap(Array[i+1], Array[end]);
				return i + 1;
			}
		};

		// Heapsort
		template <class T>
		class heapsort {
		public:

			void operator()(T Array[], int size) {
				build_max_heap(Array, size);
				int size_ = size;
				for (unsigned i = size - 1; i > 0; i--) {
					std::swap(Array[i], Array[0]);
					size_--;
					max_heapify(Array, size_, 0);
				}
			}

		private:
			int parent(int i) {
				if (i == 0) return i;
				else return (i - 1) / 2;
			}
			int left(int i) {
				return i * 2 + 1;
			}
			int right(int i) {
				return i * 2 + 2;
			}

			void max_heapify(T A[], int size, int node) {
				int l = left(node); 
				int r = right(node); 
				int largest = node; 

				if (A[node] < A[l] && l < size) 
					largest = l;

				if (A[largest] < A[r] && r < size) 
					largest = r; 
				
				if (largest != node) {
					std::swap(A[node], A[largest]);
					max_heapify(A, size, largest); 
				}
			}

			void build_max_heap(T A[], int size) {
				for (unsigned i = size / 2; i > 0; i--) {
					max_heapify(A, size, i);
				} 
				max_heapify(A, size, 0);
			}

		};
	}
}

#endif // !SORTING_ALGOS_HPP
