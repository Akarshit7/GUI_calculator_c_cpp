#include "header_file.h"





int charTointeger(char out[])
{
    long long int temp = 0;
    long long int len = strlen(out);
    for (int i = 0; i <len ; i++) {
        temp = temp * 10 + (out[i] - '0');
    }
    //std::cout<<out<<" "<<len<<std::endl;
    //std::cout<<temp<<std::endl;
    return temp;
}

char* convertIntegerToChar(int N)
{
 
    // Count digits in number N
    bool was_negative=false;
    if(N<0){
        N=N*(-1);
        was_negative=true;
    }
    int m = N;
    int digit = 0;
    while (m) {
 
        // Increment number of digits
        digit++;
 
        // Truncate the last
        // digit from the number
        m /= 10;
    }
 
    // Declare char array for result
    char* arr;
 
    // Declare duplicate char array
    char arr1[digit];
 
    // Memory allocation of array
    arr = new char[digit];
 
    // Separating integer into digits and
    // accommodate it to character array
    int index = 0;
    while (N) {
 
        // Separate last digit from
        // the number and add ASCII
        // value of character '0' is 48
        arr1[++index] = N % 10 + '0';
 
        // Truncate the last
        // digit from the number
        N /= 10;
    }
    //for adding "-" character in starting of negative output
    if(was_negative){
      strcat(arr1,"-");
      index=index+1;
    }
 
    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
 
    // Char array truncate by null
    arr[i] = '\0';
 
    // Return char array
    return (char*)arr;
}