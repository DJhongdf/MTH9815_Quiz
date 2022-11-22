#include<iostream>
#include<algorithm>
#include<vector>

int Partition(std::vector<double>& vec, int left, int right) {
	// vec: the unsorted vec
	// left: the start index for sorting
	// right: the right index for sorting
	// returns the index of the pivot in the sorted vector

	// take the last one as the pivot
	double pivot = vec[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; ++j) {
		if (vec[j] <= pivot) {
			i += 1;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[i + 1], vec[right]);
	return i + 1;
}

void Quicksort(std::vector<double>& vec, int left, int right) {
	if (left < right) {
		// put elements smaller than the pivot to its left side, 
		// elements larger than the pivot to its right side.
		int pivot_index = Partition(vec, left, right);
		// sort the left side
		Quicksort(vec, left, pivot_index - 1);
		// sort the right side
		Quicksort(vec, pivot_index + 1, right);
	}
}


class maxheap {
private:
	std::vector<double> elements = {0};
	int heapsize;
	int realsize = 0;
public:
	// the construct function gives the size of the heap
	maxheap (int size):heapsize(size) {
	}

	// add an element to the maxheap
	void Add(double value) {
		realsize += 1;
		// when adding too many elements
		if (realsize > heapsize) {
			realsize -= 1;
			std::cout << "add too many elements\n";
			return;
		}
		elements.push_back(value);
		int index = realsize, parent = index / 2;
		// compare child with parent, swap if child is larger than parent
		while (elements[index] > elements[parent] && index > 1) {
			std::swap(elements[index], elements[parent]);
			// move on until it comes to the root
			index = parent;
			parent = index / 2;
		}
	}

	// remove the largest element from the maxheap
	double Dequeue() {
		if (realsize == 0) {
			std::cout << "There are no elements\n";
			return -1;
		}
		else {
			// exchange the largest element with the last one
			double ans = elements[1];
			elements[1] = elements[realsize];
			realsize -= 1;
			int index = 1;

			// check from the root. If child is larger, swap
			while (index <= realsize / 2) {
				int left = 2 * index;
				int right = 2 * index + 1;
				if (elements[index] < elements[left] || elements[index] < elements[right]) {
					if (elements[left] > elements[right]) {
						std::swap(elements[index], elements[left]);
						index = left;
					}
					else {
						std::swap(elements[index], elements[right]);
						index = right;
					}
				}
				else break;
			}
			return ans;
		}
	}

	// print the elements of the heap
	void Print() {
		if (realsize == 0) {
			std::cout << "no elements";
		}
		for (int i = 1; i <= realsize; ++i) std::cout << elements[i] << " ";
		std::cout << "\n";
	}
};


int main() {
	std::cout << "Exercise 1:\n";
	std::vector<double> vec = { 2,8,1,5,78,100,0,134 };
	Quicksort(vec, 0, 7);
	for_each(vec.begin(), vec.end(), [](double i) {std::cout << i << " "; });
	std::cout << "\n\n";

	std::cout << "Exercise 2:\n";
	maxheap heap(5);
	heap.Print();
	heap.Add(45);
	heap.Add(30);
	heap.Add(97);
	heap.Add(120.34);
	heap.Add(140);
	heap.Add(1);
	heap.Print();
	heap.Dequeue();
	heap.Print();
	heap.Dequeue();
	heap.Print();
	
}
