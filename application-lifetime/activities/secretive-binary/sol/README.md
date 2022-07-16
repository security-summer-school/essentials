# Challenge: Secretive

We have a binary, `secretive`, and a header file, `hide_flag.h`.
The header file contains a single function, that takes a `flag` parameter.
When running the binary, it prints "No".
The solution is to overload the `print_flag` function, with one that displays the actual received parameter, as shown in the `my-own-puts` activity.
