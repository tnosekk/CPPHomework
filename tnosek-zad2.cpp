#include <iostream>
#include <stdlib.h>

bool is_prime(int n){ 
    //check if number is prime, returns True if prime and False if not prime
    if(n<=1) return false;
    if(n==3) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
return true;
} 
void print_primes(int min, int max){
    //print primes in range from m to n
    for(int i = min; i <= max; i++)
        if(is_prime(i)) printf("%i, ",i);
} 
int num_primes(int min, int max){ 
    //count prime numbers in range from min to max
    int n = 0;
    for(int i=min;i<=max;i++)
        if(is_prime(i)) n+=1; 
    return n;
}

int main(){

  print_primes(50,150);

  for(int i=0;i<1000;i+=100){
      int min = 1;
      int max = 100;
      printf("\nBetween %i and %i there are %i prime numbers\n",min+i ,max+i, num_primes(1+i,100+i));
  }
  return 0;
}


