#include <vector>
#include <cassert>
using namespace std;
class MaxHeap
{
private:
    vector<int> heap;
    int size;
public:
    void make_heap(vector<int>& nums, int s)
    {
        //构建堆
        heap.assign(nums.begin(), nums.end());
        size =  s;
        for (int i = size / 2 - 1; i >= 0; i--)
            down(i);
    }
    void push(int num)
    {
        //插入元素
        heap.push_back(num);
        size++;
        up(size - 1);
    }
    int pop()
    {
        //删除元素
        assert(size > 0);
        int result = heap[0];
        heap[0] = heap[size - 1];
        heap.pop_back();
        size--;
        down(0);
        return result;
    }
    void down(int index)
    {
        assert(index >= 0);
        int temp = heap[index];
        index = index * 2 + 1;
        while (index < size)
        {
            if (index + 1 < size && heap[index] < heap[index + 1]) index++;
            if (heap[index] < temp) break;
            else
            {
                heap[(index - 1) / 2] = heap[index];
                index = index * 2 + 1;
            }
        }
        heap[(index - 1) / 2] = temp;
    }
    void up(int index)
    {
        assert(index < size);
        int temp = heap[index];
        while (index > 0 && temp > heap[(index - 1) / 2])
        {
            heap[index] = heap[(index - 1) / 2];
            index = (index - 1) / 2;
        }
        heap[index] = temp;
    }
};
