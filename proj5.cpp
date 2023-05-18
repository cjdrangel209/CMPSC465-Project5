/**

*File Name: proj5.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

*Assisted by and Assisted line numbers:


*Your Name: Cory Drangel

*Your PSU user ID:  cjd209

*Course title: CMPSC465 Summer 2022 

*Due Time: 11:59 pm, Sunday, July 10, 2022

*Time of Last Modification: 11:40 pm, Sunday, July 10, 2022

*Description: takes an array of numbers and determines how many inversions are to take place
to get an ordered array
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void mergesort(int numArray[], int l, int r, int *inversions);
void merge(int numArray[], int l, int m, int r, int *inversions);


int main() {
  int n;
  ifstream inFile;
  string str, str1;

  inFile.open("input.txt");

  if(inFile){
    inFile >> n;

    getline(inFile, str);

    while(n != 0){
      
      int num, count =0, inversions = 0;
      int numArray[100];

      getline(inFile, str);

      while (!str.empty()) {
        int i = str.find(' ');
              
        str1 = str.substr(0, i);

        num = stoi(str1);
        numArray[count] = num;
        count++;

        if (i == -1) {
          str.erase(0, 1);
          break;
        }
        else {
          str.erase(0, i + 1);
        }
      }

      mergesort(numArray, 0, count, &inversions);

      cout << "The sequence has " << inversions << " inversions." << endl;
            
      n--;
    }
  }
  else{
    cout << "File did not open properly." << endl;
  }
}

void mergesort(int numArray[], int l, int r, int *inversions) {
    if (l < r) {
        int m = (l + (r-1))/ 2;

        mergesort(numArray, l, m, inversions);
        mergesort(numArray, m + 1, r, inversions);
        merge(numArray, l, m, r, inversions);
    }
}

void merge(int numArray[], int l, int m, int r, int *inversions) {
    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1, n2 = r - m;
    int B[100], C[100];
  

    for (int n = 0; n < n1; n++) {
        B[n] = numArray[l + n];
    }
    for (int o = 0; o < n2; o++) {
        C[o] = numArray[m + 1 + o];
    }

    while (i < n1 && j < n2) {
        if (B[i] <= C[j]) {
            numArray[k] = B[i];
            i++;
        }
        else {
            numArray[k] = C[j];
            j++;
            (*inversions)++;
        }
      k++;
    }

    while (i < n1) {
        numArray[k] = B[i];
        i++;
        k++;
    }

    while (j < n2) {
        numArray[k] = C[j];
        j++;
        k++;
    }
}
