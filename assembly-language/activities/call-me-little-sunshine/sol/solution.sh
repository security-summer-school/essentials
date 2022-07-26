#! /bin/bash

nm main | grep godzilla
# The address of godzilla is 0x401462, i.e. 4199522.

echo 4199522 | ./main
