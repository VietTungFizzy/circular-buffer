#include<vector>
#include<iostream>

#define THE_END_OF_BUFFER &datas[datas.size()]

template<typename T>
class CircularBuffer {
public:
  CircularBuffer() {}
  CircularBuffer(unsigned int size, T default_value) {
    datas = std::vector<T>(size, default_value);
    read_ptr = write_ptr = &datas[0];
    amount_of_data_in_buffer = 0;
    this->default_value = default_value;
  }
  void insert(T data) {
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
  T read_data() {
    if(isEmpty() == true) return -1;

    T temp = *read_ptr;
    *read_ptr = default_value;
    read_ptr++;
    amount_of_data_in_buffer--;
    if(read_ptr == THE_END_OF_BUFFER)
      read_ptr = &datas[0];
    return temp;
  }
  bool isFull() {
    if(amount_of_data_in_buffer == datas.size() && write_ptr == read_ptr){
      //std::cout<<"Buffer is full\n";
      return true;
    }
    return false;
  }
  bool isEmpty() {
    if(amount_of_data_in_buffer == 0 && write_ptr == read_ptr){
    //std::cout<<"Buffer is empty\n";
      return true;
    }
    return false;
  }
private:
  std::vector<T> datas; //only allow to buffer to hold (size -1) items
  T * read_ptr;
  T * write_ptr;
  T default_value;
  unsigned int amount_of_data_in_buffer;
};
