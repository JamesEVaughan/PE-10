A solution to Project Euler #10 written in C. Please don't use this to cheat.

Problem (quoted from projecteuler.net/problem=10):
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

My solution takes the base ideas from my oft used PrimeLister (a singly linked
list using a seive to find the next prime number) and writing it in C standard 
code. As such, CPrimeLister becomes a struct with a family of helper functions.

This is my first attempt at working with objects in C and I do hope my OOP
background doesn't show too much. :)