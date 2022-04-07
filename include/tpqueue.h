// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T arr[100];
  int first, last;

 public:
  TPQueue() : first(0), last(0) {}
  void push(T x) {
    int tmp = ++last - 1;
    while ((tmp - 1) >= first) && (arr[(tmp + 1) % size].prior < x.prior)) {
      arr[tmp % size] = arr[(tmp + 1) % size];
      --tmp;
    }
    arr[(tmp % size)] = x;
  }
  T pop() {
    return arr[(first++) % size];
  }
  int getSize() {
    return (last - first) % (size + 1);
  }
  T front() {
    if (first < last) {
      return arr[first];
    }
  }
  T back() {
      return arr[last - 1];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
