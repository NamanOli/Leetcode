https://practice.geeksforgeeks.org/problems/swap-bits5726/1

```
 unsigned int a = (x >> p1) & ((1U << k) - 1);   // 00000111
        unsigned int b = (x >> p2) & ((1U << k) - 1);   // 00000001
        unsigned int c = (a ^ b);                       // 00000110
        c = ((c << p1)  | (c << p2));                   // 11001100
        
        return (x ^ c);     // 00101111 ^ 11001100 => 11100011(227)
        
```



Prerequisite knowledge to solve the problem 

To set a bit use or 
To unset a bit use and 
If (a ^ b)== c
b = a ^ c
a = b ^ c
To swap N bits  let's consider an example 

47 => 00101111

a = 111 (say)

b = 001 (say)

c = a ^ b => 110

 

Now, To perform xor operation on index from p1 and p2 we require ..110…110…. form. 

so, we would update c as 

   c = (c << p1) | (c << p2);
