#include <bits/stdc++.h>
using namespace std;

/*
    This program implements both Max Heap and Min Heap data structures from scratch
    using a vector-based array representation of a complete binary tree.

    Two classes are provided:

    1. MaxHeap:
       - Maintains the largest element at the root.
       - Supports insertion using heapify-up.
       - Supports deletion of the maximum element using heapify-down.
       - Provides utility functions such as getMax(), isEmpty(), and size().
       - Time Complexity:
            Insert      : O(log n)
            Delete Max : O(log n)
            Get Max    : O(1)
       - Space Complexity: O(n)

    2. MinHeap:
       - Maintains the smallest element at the root.
       - Supports insertion using heapify-up.
       - Supports deletion of the minimum element using heapify-down.
       - Provides utility functions such as getMin(), isEmpty(), and size().
       - Time Complexity:
            Insert      : O(log n)
            Delete Min : O(log n)
            Get Min    : O(1)
       - Space Complexity: O(n)

    Both heaps use the following index relationships in the underlying array:
       - Parent index  = (i - 1) / 2
       - Left child    = 2*i + 1
       - Right child   = 2*i + 2

    These implementations demonstrate how priority queues work internally and
    showcase manual heap operations without relying on STL priority_queue.
*/

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] < heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int getMax() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

class MinHeap {
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] > heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int getMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};