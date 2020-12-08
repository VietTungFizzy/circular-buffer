#include "circular-buffer.h"

CircularBuffer::CircularBuffer(int size) {
  datas = std::vector<int>(size, -1);
  read_ptr = write_ptr = &datas[0];
  amount_of_data_in_buffer = 0;
}

void CircularBuffer::insert(int data) {
  if(isFull()) {
    std::cout<<"Start overwriting....\n";
    *write_ptr = data;
    write_ptr++;
    if(write_ptr == THE_END_OF_BUFFER) write_ptr = &datas[0];
  }
  else {
    *write_ptr = data;
    write_ptr++;
    amount_of_data_in_buffer++;
    if(write_ptr == THE_END_OF_BUFFER) write_ptr = &datas[0];
  }
}
int  CircularBuffer::read_data() {
  if(isEmpty() == true) return -1;

  int temp = *read_ptr;
  *read_ptr = -1;
  read_ptr++;
  amount_of_data_in_buffer--;
  if(read_ptr == THE_END_OF_BUFFER)
    read_ptr = &datas[0];
  return temp;
}
bool CircularBuffer::isFull() {
  if(amount_of_data_in_buffer == datas.size() && write_ptr == read_ptr){
    //std::cout<<"Buffer is full\n";
    return true;
  }
  return false;
}

bool CircularBuffer::isEmpty() {
  if(amount_of_data_in_buffer == 0 && write_ptr == read_ptr){
    //std::cout<<"Buffer is empty\n";
    return true;
  }
  return false;
}
