/*
The last example in this section that jumped back to ```begin``` could 
be better written using a loop. Rewrite the code to eliminate the ```goto```.

// original code:
begin:
  int sz = get_size();
  if (sz <= 0) {
      goto begin;
  }
*/

// improved code
while ((int sz = get_size()) <= 0)
    ;
