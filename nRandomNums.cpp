#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void sortAndShift(int[], int, int);
void swap(int[], int, int);

int main (int argc, char** argv){
  if (argc != 3){
    cerr << "Syntax is: nRandNums [number of values] [max value]" << endl;
    return 1;
  }
  const int n = atoi(argv[1]);
  const int max = atoi(argv[2]);
  int* numbers = new int[n];

  //Fill the array with initial values
  for(int i = 0; i < n; ++i)
    numbers[i] = (rand() % max);

  //Sort numbers and modify matches
  sortAndShift(numbers, n, max);

  //write the numbers to file
  ofstream outFile("numbers.txt");
  for(int i = 0; i < n; ++i){
    outFile << numbers[i] << endl;
  }
  return 0;
}

void sortAndShift(int numbers[], int n, int max){
  bool finished = false;
  while(!finished){
    finished = true;
    for(int i = 0; i < n-1; ++i){
      if(numbers[i] == numbers[i+1]){
        numbers[i+1] = (rand() % max);
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
