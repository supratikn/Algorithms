#include "stdafx.h"
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
//comparator for a min-heap; may be required in further operations
//class minHeapComparator {
//public: int operator()(const int& p, const int& q) {
//	return p < q;
//}
//};
////add to the correct heap
//void addToHeap(const int& num, std::priority_queue<int>* low,  
//	std::priority_queue<int,std::vector<int>,minHeapComparator>* high) {
//
//	if (low->empty() || num < low->top())
//		low->push(num);
//	
//	else high->push(num);
//}
////rebalance the heaps
//void rebalance( std::priority_queue<int>* low, 
//	std::priority_queue<int, std::vector<int>, minHeapComparator>* high) {
//	//more lower values 
//	if ((low->size() - high->size())>1) {
//		high->push(low->top());
//		low->pop();
//	}
//	//more higher values
//	else if ((high->size() - low->size()) > 1) {
//		low->push(high->top());
//		high->pop();
//	}
//		
//}
////get the median value from the heaps
//double getMedian(const std::priority_queue<int>* low, 
//	const std::priority_queue<int, std::vector<int>, minHeapComparator>* high) {
//	if (low->size() != high->size())
//		return low->size() > high->size() ? low->top() : high->top();
//
//	return (double)((low->top() + high->top()) / 2.0);
//}

double getMedian(const std::set<int>& set) {
	if (set.empty())throw  std::runtime_error("");//practically impossible situation but needed as a fail safe

	int size = set.size();

	if (size == 1)return *(set.begin());//return the only element in the set

	auto it = set.begin();

	std::advance(it, size / 2);//advance the iterator to roughly half the elements in the red-black tree

	if (size % 2 != 0) {
		
		return *it;//if odd number of elements, return the median
	}
	else {
		//take the average of the middle two elements
		auto med = it;
		it--;

		return (double)(*it + *med) / 2.0;
	}	
}
//calculate the median when each new element is added to the vector
std::vector<double> medians(const std::vector<int>& vec) {
	//std::vector<double> retval(vec.size());

	//std::priority_queue<int>* low= new std::priority_queue<int>();//max heap
	//std::priority_queue<int, std::vector<int>, minHeapComparator>* high
	//	= new std::priority_queue<int, std::vector<int>, minHeapComparator>();//min heap

	//for (unsigned int i = 0; i < vec.size(); i++) {
	//	
	//	addToHeap(vec.at(i), low, high);
	//	rebalance(low, high);
	//	retval.at(i) = getMedian(low, high);
	//}

	//delete low, high;
 //   return retval;

	std::vector<double> retval (vec.size());

	std::set<int>set;

	for (unsigned int i = 0; i < vec.size(); i++) {
		set.emplace(vec.at(i));
		retval.at(i) = getMedian(set);
	}


	
	return retval;
}



