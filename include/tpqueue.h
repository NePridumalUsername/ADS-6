// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int first;
    int last;

 public:
    TPQueue() : first(0), last(0) { arr = new T[size]; }
    void push(T x) {
        if (last - first >= size) {
            return;
        } else {
            int i = last++;
            while (i != first && x.prior > arr[(i - 1) % size].prior) {
                arr[i % size] = arr[(i - 1) % size];
                i--;
            }
            arr[i % size] = x;
        }
    }
    T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
