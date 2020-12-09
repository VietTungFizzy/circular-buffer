#include "circular-buffer.h"
#include "circular-buffer-index-version.h"
#ifdef _WIN32
#include <conio.h>
#elif unix
#include <stdio.h>
#endif

int main(int argc, char* argv[]) {
  CircularBuffer<char> c = CircularBuffer<char>(5, ' ');
  //CircularBufferIndex * c = new CircularBufferIndex(5);
  char key_press;
  int ascii_value;
  #ifdef _WIN32
    while(1) {
      key_press = getch();
      ascii_value = (int)key_press;
      if(ascii_value == 27) //For ESC
        break;
      switch(ascii_value) {
        case 32:/*For SPACE*/
          for(int i = 0; i< 5; i++) {
              std::cout<<c.read_data()<<"_";
          }
          std::cout<<"\r";
          break;
        case 96: //For ` key
          system("clear");
          break;
        default:
          c.insert(key_press);
          break;
      }
    }
  #elif unix
    system("stty raw -echo");
    while(1) {
      key_press = getchar();
      ascii_value = (int)key_press;
      if(ascii_value == 27) //For ESC
        break;
      switch(ascii_value) {
        case 32:/*For SPACE*/
          for(int i = 0; i< 5; i++) {
              std::cout<<c.read_data()<<"_";
          }
          std::cout<<"\r";
          break;
        case 96: //For ` key
          system("clear");
          break;
        default:
          c.insert(key_press);
          break;
      }
    }
    system("stty cooked echo");
  #endif
  return 0;
}
