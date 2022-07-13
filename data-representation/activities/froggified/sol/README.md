First, we observe that we have `binary` text, so we decode it and get the fake flag: `SSS{are_you_a_computer}`.  
Next up, we see that the text looks like `ASCII`, so we decode it as `decimal`, thus getting the next fake flag: `SSS{nope_still_a_human}`.  
After that, we see that all digits higher than 7 are gone, so we immediately think of `octal`, which will get us to the next fake flag: `SSS{you_look_like_you_know_linux_permissions}`.  
We see a lot of `0x`s, so we know to decode from `hexadecimal` and we get to the last fake flag: `SSS{you_love_tic_tac_toe_huh}`.  
In the end, we observe the text is encoding in `Base64`, so we decode it to get the real flag.
