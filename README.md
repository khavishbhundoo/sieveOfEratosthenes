# sieveOfEratosthenes
Find primes within a range using the [Sieve Of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).It is a simple but fast algorithm that i choose to implement to use in other projects and get familiar with C++.It is able to generate primes from one to one billion in around 9.2 seconds on my machine

# Prerequisits

`cmake3`

# Build Intructions

Go into the directory that contain this README and enter the following commands

`mkdir -p build`

`cd build`

`cmake3 ..`

`make` 

You can then run the binary  as follows `./SieveOfEratosthenes`

# Performance

`Runtime to generate primes : 9201 ms`

`Number of primes : 50847534`

`Primes saved to sieve.txt`

