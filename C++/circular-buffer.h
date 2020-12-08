#include<vector>
#include<iostream>

#define THE_END_OF_BUFFER &datas[datas.size()]

class CircularBuffer {
public:
  CircularBuffer() {}
  CircularBuffer(int size);
  void insert(int data);
  int read_data();
  bool isFull();
  bool isEmpty();
  void test();
private:
  std::vector<int> datas; //only allow to buffer to hold (size -1) items
  int * read_ptr;
  int * write_ptr;
  unsigned int amount_of_data_in_buffer;
};
