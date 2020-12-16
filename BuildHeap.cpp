#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    if(vector.size()==0)
    	return {};
		int i,sz=vector.size(),first_parent = (sz-2)/2;
		for(i=first_parent;i>=0;i--)
			siftDown(i,sz-1,vector);
		return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    int child_one = 2*currentIdx + 1;
		int child_two, min_idx;
		while(child_one<=endIdx)
		{
			child_two = 2*currentIdx + 2;
			if((child_two<=endIdx) && (heap[child_two]<heap[child_one]))
				min_idx = child_two;
			else
				min_idx = child_one;
			if(heap[currentIdx]>heap[min_idx])
			{
				swap(currentIdx,min_idx,heap);
				currentIdx = min_idx;
				child_one = 2*currentIdx + 1;
			}
			else
				return;
		}
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    int parent_idx = (currentIdx-1)/2;
		while(parent_idx>0)
		{
			if(heap[currentIdx] < heap[parent_idx])
			{
				swap(currentIdx,parent_idx,heap);
				currentIdx = parent_idx;
				parent_idx = (currentIdx-1)/2;
			}
			else
				return;
		}
  }

  int peek() {
    if(heap.size()==0)
    	return -1;
		return heap[0];
  }

  int remove() {
    if(heap.size()==0)
    	return -1;
		int remove = heap[0];
		swap(0,heap.size()-1,heap);
		heap.pop_back();
		siftDown(0,heap.size()-1,heap);
		return remove;
  }

  void insert(int value) {
    heap.push_back(value);
		int idx = heap.size()-1;
		siftUp(idx,heap);
  }
	void swap(int idx1,int idx2,vector<int>& heap)
	{
		int temp = heap[idx1];
		heap[idx1] = heap[idx2];
		heap[idx2] = temp;
	}
};
