
// Created by cmestre on 18/04/2023.
//Práctica realizada por Francisco González Prieto y Juan Manuel Muñoz del Cerro

#include "max_heap.h"

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::left(int i) {
     return 2 * i + 1;
}

int MaxHeap::right(int i) {
    return 2 * i + 2;
}

void MaxHeap::heapifyUp(int i) {
    while (i > 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::heapifyDown(int i) {
    int maxIndex = i;
    int l = left(i);
    int r = right(i);
    if (l < heap.size() && heap[l] > heap[maxIndex]) {
        maxIndex = l;
    }
    if (r < heap.size() && heap[r] > heap[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(heap[i], heap[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MaxHeap::extractMax() {
    if (heap.size() == 0) {
        throw "Heap vacio";
    }
    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return root;
}

bool MaxHeap::isEmpty() {
   return heap.size() == 0;
}
