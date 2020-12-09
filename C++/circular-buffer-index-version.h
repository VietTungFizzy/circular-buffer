#include <vector>
#include <iostream>

class CircularBufferIndex {
public:
  CircularBufferIndex() {}
  CircularBufferIndex(int size);
  void insert(int data);
  int read_data();
  bool isFull();
  bool isEmpty();
private:
  std::vector<int> datas;
  int read_index;
  int write_index;
  unsigned int amount_of_data_in_buffer;
};
