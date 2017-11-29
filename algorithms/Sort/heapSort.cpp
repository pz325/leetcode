#include "util.hpp"

#include <stdexcept>

class Heap
{
    public:
        /**
         * build heap from a list of elements
         * 
         * assume the heap is empty
         */ 
        void buildFrom(const std::vector<int>& v);

        /**
         * add v to the end of the heap
         * then heapfy
         */ 
        void add(int v);

        /**
         * pop root element from the heap
         * replace the root with the last element in the heap
         * the heapfy
         */ 
        int popRoot();

        /**
         * print heap (array) to stdout
         */ 
        void log();

    private:

        /**
         * Heapfy from a leaf node at index
         */ 
        void heapfyFromLeaf(int index);

        /**
         * Heapfy from the root
         */ 
        void heapfyFromRoot();

        std::vector<int> heap_;
        int size_ = 0;
};

void Heap::log()
{
    std::cout << "size: " << size_ << " -> ";
    for (auto node : heap_)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

void Heap::buildFrom(const std::vector<int> &v)
{
    if (size_ != 0)
    {
        throw std::runtime_error("Cannot build from an non-empty heap");
    }

    heap_.reserve(v.size());
    for (auto i: v)
    {
        std::cout << "buildFrom: adding " << i << std::endl;;
        heap_.push_back(i);
        ++size_;
        heapfyFromLeaf(size_-1);
        log();
        std::cout << std::endl;
    }
}

int Heap::popRoot()
{
    if (size_ == 0)
    {
        throw std::runtime_error("No root to pop for an empty heap");
    }

    const int ret = heap_[0];
    std::cout << "popRoot pop " << ret << std::endl;
    heap_[0] = heap_[size_-1];
    --size_;
    heapfyFromRoot();

    std::cout << "popRoot done" << std::endl;
    log();
    std::cout << std::endl;
    return ret;
}

void Heap::heapfyFromLeaf(int index)
{
    while(index > 0)
    {
        int parentIndex = (index + 1) / 2 - 1;
        if (heap_[parentIndex] < heap_[index])
        {
            int tmp = heap_[parentIndex];
            heap_[parentIndex] = heap_[index];
            heap_[index] = tmp;
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void Heap::heapfyFromRoot()
{
    int rootIndex = 0;
    while (true)
    {
        int leftChildIndex = rootIndex * 2 + 1;
        if (leftChildIndex >= size_)
        {
            break;
        }


        int rightChildIndex = leftChildIndex + 1;
        if (rightChildIndex < size_ 
            && heap_[rootIndex] < heap_[rightChildIndex]
            && heap_[rightChildIndex] >= heap_[leftChildIndex])
        {
            int tmp = heap_[rootIndex];
            heap_[rootIndex] = heap_[rightChildIndex];
            heap_[rightChildIndex] = tmp;
            rootIndex = rightChildIndex;
            continue;
        }

        if (heap_[rootIndex] < heap_[leftChildIndex])
        {
            int tmp = heap_[rootIndex];
            heap_[rootIndex] = heap_[leftChildIndex];
            heap_[leftChildIndex] = tmp;
            rootIndex = leftChildIndex;
            continue;
        }

        break;
    }
}


void heapSort(std::vector<int> &v)
{
    Heap heap;
    heap.buildFrom(v);

    int i = v.size()-1;
    while (i >= 0)
    {
        v[i] = heap.popRoot();
        --i;
    }
}

int main()
{
    std::vector<int> v{9, 2, 3, 6, 5, 10, 7, 11, 8};
    heapSort(v);
    printV(v);
    return 0;
}
