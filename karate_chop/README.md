This Directory is for the [Karate Chop](http://codekata.com/kata/kata02-karate-chop/) exercise from __Code Kata__.

__Karate Chop__ is a standard binary search algorithm that acts on an array of integers.

The solution is simple:

1. Start at the middle Element
2. Check if you've found the number you're looking for, otherwise
3. If the number is greater than the current element, repeat from step 1 using the right half, else
3. If the number is less than the current element, repeat from step 1 using the left half.

The only challenge to this problem is trying to catch all those pesky "off by one" errors that are all too common when dealing with arrays or strings.
