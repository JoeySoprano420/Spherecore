Define_function(factorial, x)
    If_true (x <= 1) Return(1) End_if
    Return (x * factorial(x-1))
End_function
