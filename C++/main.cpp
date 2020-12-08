#include "circular-buffer.h"
#include "circular-buffer-index-version.h"

int main(int argc, char* argv[]) {
  //CircularBuffer * c = new CircularBuffer(5);
  CircularBufferIndex * c = new CircularBufferIndex(5);
  c->insert(5);
  c->insert(10);
  c->insert(15);
  c->insert(20);
  c->insert(25);
  c->insert(30);

  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<std::endl;

  c->insert(-5);

  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;
  std::cout<<c->read_data()<<std::endl;

  return 0;
}
