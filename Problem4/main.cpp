#include <iostream>
#include <stdio.h>
#include "Prime.h"

using namespace std;

void ProblemFourA(char[]);
size_t findLength(char[]);

template <int rows, int cols>
void ProblemFourB(int (&arr)[rows][cols], int);

int ProblemFourC(int);

int main() {
    //  Problem 4A
    char word[] = "Michelle";
    ProblemFourA(word);
    printf(word);
    cout << endl << endl;

    //  Problem 4B
    int array[2][2] = {{1, 7}, {2, 3}};
    ProblemFourB(array,8);

    //Problem 4C
    return 0;
}

void ProblemFourA(char str[]) {  //  a function to reverse a string (or char array)
    int length = findLength(str);  //  determining the length of the char array using the function, findLength
    int i;  //  initializing i
    for(i=0; i < length/2; ++i) {  //  a loop to search through the first half of the char array
        str[length] = str[i];  //  setting the last char to equal the i-th char
        str[i] = str[length-i-1];
        str[length-i-1] = str[length];
    }
    str[length] = '\0';  //  reassigning null character
}

size_t findLength(char str[]) {  //  a function to determine the length of the char array
    int i, length = 0;  //  initializing i and length to be 0
    for(i=0; str[i]; ++i)  //  a loop to search through the char array
        ++length;  //  increasing the length by one through every iteration of the loop
    return length;  //  returning the length of the char array
}

template <int rows, int cols>  //  a template to allow the user to input any size 2D array
void ProblemFourB(int (&arr)[rows][cols], int sum) {  //  a function that takes a 2D array and an int and finds which elements sum up to the int
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = i; k < rows; k++) {
                for (int l = j; l < cols; l++) {
                    if (arr[i][j] + arr[k][l] == sum) {
                        cout << "(" << arr[i][j] << "," << arr[k][l] << ")" << endl;  //  printing out the elements that sum up to the desired value
                    }
                }
            }
        }
    }
}

int ProblemFourC(int n) {
    int tail = 1;
    int size = 100;
    int array[size];
    array[0] = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    int result = (9 ^ i) * (15 ^ j) * (7 ^ k);
                    array[tail] = result;
                    tail ++;
                }
            }
    }
    int i, j, temp;
    for (i = 1; i <= size; i++) {
        j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;  //  decreasing j by 1
            cout << array[j] << endl;
        }
    }
    return array[n];
}