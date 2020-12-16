#include <vector>
using namespace std;

void swap(vector<int>& array,int a,int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
void sift_down(int current_idx,int max_idx,vector<int>& array)
{
	int child_1 = current_idx*2 + 1, child_2, min_idx;
	while(child_1 <= max_idx)
	{
		child_2 = current_idx*2 + 2;
		if((child_2 <= max_idx) && (array[child_2]<array[child_1]))
			min_idx=child_2;
		else
			min_idx=child_1;
		if(array[min_idx]<array[current_idx])
		{
			swap(array,min_idx,current_idx);
			current_idx = min_idx;
			child_1 = current_idx*2 + 1;
		}
		else
			return;
	}
}
vector<int> buildheap(vector<int>& array)
{
	int i,sz=array.size(),first_parent=(sz-2)/2;
	for(i=first_parent;i>=0;i--)
		sift_down(i,sz-1,array);
	return array;
}
vector<int> heapSort(vector<int> array) {
  int i,sz=array.size();
	if(sz==0)
  	return {};
	array = buildheap(array);
	vector<int>res;
	for(i=0;i<sz;i++)
	{
		res.push_back(array[0]);
		swap(array,0,array.size()-1);
		array.pop_back();
		sift_down(0,array.size()-1,array);
	}
	/*
	for(i = sz-1;i>0;i--)
	{
	swap(array,0,i);
	sift_down(0,i-1,array);
	}
	*/
	return res;
}
