#include "circular-buffer.h"

CircularBuffer::CircularBuffer(int size) {
  datas = std::vector<int>(size, -1);
  buffer_end = &datas[0];
  write_ptr = buffer_end+1;
}

void CircularBuffer::insert(int data) {
  *write_ptr = data;
  write_ptr++;
  if(write_ptr == &datas[datas.size()]) {
    std::cout<<"Buffer Full....... Start Overwriting\n";
    write_ptr = buffer_end +1;
  }
}
int  CircularBuffer::read_data() {
  for(int i = 0; i < datas.size(); i++) {
    std::cout<<datas[i]<<std::endl;
  }
  return 0;
}
bool CircularBuffer::isFull() {
  return (buffer_end == write_ptr) ? true : false;
}

bool CircularBuffer::isEmpty() {
  return (buffer_end+1 == write_ptr) ? true : false;
}
