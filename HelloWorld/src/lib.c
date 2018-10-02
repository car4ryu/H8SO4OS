#include "defines.h"
#include "serial.h"
#include "lib.h"

int putc(unsigned char c) {
  if (c == '\n') serial_send_byte(SERIAL_DEFAULT_SERVICE, '\r');
  return serial_send_byte(SERIAL_DEFAULT_SERVICE, c);
}

int puts(unsigned char *str) {
  while(*str)
    putc(*(str++));
  return 0;
}
