# Tail recursion example

Just a small program I wrote inspired by this video: https://www.youtube.com/watch?v=_JtPhF8MshA.

I wanted to see the effects of a tail recursive function vs a non-tail recursive function. The results were pretty amazing. The tail recursive function is several orders of magnitude faster

Output using -O3 with gcc version 9.3.0 on i7-8700K CPU @ 3.70GHz.

```
...
...
fib_non_tr(33) = 3524578 (12 ms)
fib_tr(33)     = 3524578 (0 ms)
fib_non_tr(34) = 5702887 (18 ms)
fib_tr(34)     = 5702887 (0 ms)
fib_non_tr(35) = 9227465 (29 ms)
fib_tr(35)     = 9227465 (0 ms)
fib_non_tr(36) = 14930352 (48 ms)
fib_tr(36)     = 14930352 (0 ms)
fib_non_tr(37) = 24157817 (77 ms)
fib_tr(37)     = 24157817 (0 ms)
fib_non_tr(38) = 39088169 (125 ms)
fib_tr(38)     = 39088169 (0 ms)
fib_non_tr(39) = 63245986 (203 ms)
fib_tr(39)     = 63245986 (0 ms)
fib_non_tr(40) = 102334155 (328 ms)
fib_tr(40)     = 102334155 (0 ms)
fib_non_tr(41) = 165580141 (531 ms)
fib_tr(41)     = 165580141 (0 ms)
fib_non_tr(42) = 267914296 (860 ms)
fib_tr(42)     = 267914296 (0 ms)
fib_non_tr(43) = 433494437 (1391 ms)
fib_tr(43)     = 433494437 (0 ms)
fib_non_tr(44) = 701408733 (2251 ms)
fib_tr(44)     = 701408733 (0 ms)
fib_non_tr(45) = 1134903170 (3646 ms)
fib_tr(45)     = 1134903170 (0 ms)
fib_non_tr(46) = 1836311903 (5939 ms)
fib_tr(46)     = 1836311903 (0 ms)
fib_non_tr(47) = 2971215073 (9716 ms)
fib_tr(47)     = 2971215073 (0 ms)
fib_non_tr(48) = 4807526976 (15912 ms)
fib_tr(48)     = 4807526976 (0 ms)
fib_non_tr(49) = 7778742049 (25249 ms)
fib_tr(49)     = 7778742049 (0 ms)
```

The reason why the tail recursive version is so much faster is that GCC O2 and above uses something called *tail call optimization* whereby the call stack is reused for every recursive call, effectively turning the recursive function into a loop.

Also, the tail recursive method consumes much less memory since the stack is reused.

https://dev.to/rohit/demystifying-tail-call-optimization-5bf3

