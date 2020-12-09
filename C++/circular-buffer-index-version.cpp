#include "circular-buffer-index-version.h"

CircularBufferIndex::CircularBufferIndex(int size) {
    datas = std::vector<int>(size, -1);
    amount_of_data_in_buffer = read_index = write_index = 0;
}
void CircularBufferIndex::insert(int data) {
  if(isFull()) {
    std::cout<<"Start overwriting.....\r";
    datas[read_index] = data;
    read_index = (read_index + 1) % datas.size();
  }
  else {
    datas[read_index] = data;
    amount_of_data_in_buffer++;
    read_index = (read_index + 1) % datas.size();
  }

}

int CircularBufferIndex::read_data() {
  if(isEmpty()) return -1;
  int temp = datas[write_index];
  datas[write_index] = -2;
  amount_of_data_in_buffer--;
  write_index = (write_index + 1) % datas.size();
  return temp;
}

bool CircularBufferIndex::isFull() {
  if(read_index == write_index && amount_of_data_in_buffer == datas.size())
    return true;
  return false;
}

bool CircularBufferIndex::isEmpty() {
  if(read_index == write_index && amount_of_data_in_buffer == 0)
    return true;
  return false;
}
