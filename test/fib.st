{% This test program computes the Nth Fibonacci number
    using recursion and iteration. %}

% global variables
const  n: int := 8
var a: array 1..10 of int
% iterative function
function itFibonacci (n: int) : int
  var Fn: int := 1
  var FNminus1: int
  var temp: int

  Fn := 1
  FNminus1 := 1
  loop
  var kkk: int
    exit when (n <= 2) 
    temp := Fn
    Fn := Fn + FNminus1
    FNminus1 := temp
    n := n - 1
  end loop
  result Fn
end itFibonacci

% main program 
put "N: "
put n 
skip
put "Result of iterative computation:  "
put itFibonacci(n)

