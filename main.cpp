#include "circular-buffer.h"

int main(int argc, char* argv[]) {
  CircularBuffer * c = new CircularBuffer(5);
  c->insert(5);
  c->insert(10);
  c->insert(15);
  c->insert(20);
  c->read_data();
  c->insert(-5);
  c->read_data();
  return 0;
}
