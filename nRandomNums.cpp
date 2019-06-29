#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void sortAndShift(int[], int, int, int);
void swap(int[], int, int);
void scrambleList(int[], int);

int main (int argc, char** argv){
  if (argc != 5){
    cerr << "Syntax is: nRandNums [number of values] [min value] [max value] [o or u]" << endl;
    return 1;
  }
  const int n = atoi(argv[1]);
  const int min = atoi(argv[2]);
  const int max = atoi(argv[3]);
  const char scram = static_cast<char>(*argv[4]);
  const int mod = max - min;
  int* numbers = new int[n];

  //Fill the array with initial values
  for(int i = 0; i < n; ++i)
    numbers[i] = (rand() % mod) + min;

  //Sort numbers and modify matches
  sortAndShift(numbers, n, min, mod);

  //re-arrange list
  if(scram == 'u'){
    for(int i = 0; i < n; ++i){
      swap(numbers[i], numbers[rand() % n]);
    }
  }

  //write the numbers to file
  ofstream outFile("numbers.txt");
  for(int i = 0; i < n; ++i){
    outFile << numbers[i] << endl;
  }
  return 0;
}

void sortAndShift(int numbers[], int n, int min, int mod){
  bool finished = false;
  while(!finished){
    finished = true;
    for(int i = 0; i < n-1; ++i){
      if(numbers[i] == numbers[i+1]){
        numbers[i+1] = (rand() % mod) + min;
        finished = false;
      }
      else if(numbers[i] > numbers[i+1]){
        swap(numbers, i, i+1);
        finished = false;
      }
    }
  }
  return;
}

void swap(int numbers[], int a, int b){
  int temp = numbers[a];
  numbers[a] = numbers[b];
  numbers[b] = temp;
  return;
}
