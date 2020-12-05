#include<vector>
#include<iostream>
class CircularBuffer {
public:
  CircularBuffer() {}
  CircularBuffer(int size);
  void insert(int data);
  int read_data();
  bool isFull();
  bool isEmpty();
private:
  std::vector<int> datas; //only allow to buffer to hold (size -1) items
  int * buffer_end;
  int * read_ptr;
  int * write_ptr;
};
