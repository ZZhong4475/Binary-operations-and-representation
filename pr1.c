//Name:Zheng Zhong

#include <stdio.h>
#define BITS 8


int main(void) {

  char repeat = 'r';
  int i,choice;
  int mask = 1<<sizeof(int)*BITS -1;
  
 while(repeat == 'r'){
  
  printf("what type of display do you want ?\n");
  printf("Enter 1 for IP/RGB,2 for character concatenation,3 for character parity,4 for filtering: ");
  scanf("%d",&choice);
  printf("Your choice is : %d\n",choice);



 /*choice == 1 operations*/
  if(choice == 1){
 //save user inputs
  unsigned int input_num;
  printf("Enter a positive integer for the IP/RGB valie:");
  scanf("%u",&input_num);
  printf("You entered: %u, Bit representation: ",input_num);

 //printout the unsigned integer bit representation
  unsigned int bit_rep = input_num;
  for(i=1;i<=sizeof(int)*BITS;i++){
  
  if(bit_rep & mask){
     putchar('1');
   }else {
     putchar('0');
   }
   bit_rep<<=1;
  if(!(i%8)){
      putchar(' ');
    }

  }

 
 //Extract the bit portions by narrowing the unsigned integer to 4 unsigned chars
 unsigned int  firstChar1 = input_num>>3*BITS;
 unsigned char firstChar = firstChar1;
 

 unsigned int  secChar1 = input_num>>2*BITS;
 unsigned char secChar = secChar1;

 unsigned int  thirdChar1 = input_num>>1*BITS;
 unsigned char thirdChar = thirdChar1;

 unsigned int  fourthChar1 = input_num;
 unsigned char fourthChar = fourthChar1;


 //print out results in dot-decimal representation
 printf("The dot-decimal represented by this number is:%u.%u.%u.%u\n",firstChar,secChar,thirdChar,fourthChar);

  }//end of the choice 1



 /*choice == 2 operations*/
 else if(choice == 2){
  
 //Save user inputs
  char input1,input2,input3,input4;
  printf("Enter 4 characters:");
  scanf(" %c%c%c%c", &input1,&input2,&input3,&input4);
  
 //printout each input and its bit representation
  char firBit = input1;
  printf("%u,Bit Representation: ",input1);
  for(i=1;i<=sizeof(char)*BITS;i++){
  
    if(firBit & mask){
     putchar('1');
   }else {
     putchar('0');
    }
   
    firBit<<=1;
  
  }
   printf("\n");

  char secBit = input2;
  printf("%u,Bit Representation: ",input2);
  for(i=1;i<=sizeof(char)*BITS;i++){
  
    if(secBit & mask){
     putchar('1');
   }else{
     putchar('0');
    }
 
    secBit<<=1;

  }
   printf("\n");

  char thirdBit = input3;
  printf("%u,Bit Representation: ",input3);
  for(i=1;i<=sizeof(char)*BITS;i++){
  
    if(thirdBit & mask){
     putchar('1');
   }else {
     putchar('0');
   }
   
    thirdBit<<=1;

  }
   printf("\n");

  char fourthBit = input4;
  printf("%u,Bit Representation: ",input4);
  for(i=1;i<=sizeof(char)*BITS;i++){
  
  if(fourthBit & mask){
     putchar('1');
   }else {
     putchar('0');
   }
   fourthBit<<=1;

  }
 printf("\n");


//concatenate all inputs
 unsigned int concatedInt,Op1,Op2,Op3,Op4;
 
 Op1 = input1;
 Op1<<=3*BITS;
 Op2 = input2;
 Op2<<=2*BITS;
 Op3 = input3;
 Op3<<=BITS;
 Op4 = input4;
 concatedInt=Op1|Op2|Op3|Op4;
 printf("32-bit concatenation is :%u, Bit Representation:",concatedInt);

//printout the concated integer bit representation
 for(i=1;i<=sizeof(int)*BITS;i++){
  
  if(concatedInt & mask){
     putchar('1');
   }else {
     putchar('0');
   }
    concatedInt<<=1;
   
   if(!(i%8)){
      putchar(' ');
    }

  }
 printf("\n");

 }//end of choice 2


/*Choice == 3 operations*/
else if(choice==3){

//save user inputs
 char inputChar;
 printf(" Enter a character for parity calculation:");
 scanf(" %c",&inputChar);
 printf("Character: %u, Bit representation:",inputChar);
 
//Display the bit representation, meanwhile, count number of ones
char bitChar = inputChar;
int numOfOnes=0;
for(i=1;i<=sizeof(char)*BITS;i++){
  
  if( bitChar& mask){
     numOfOnes++;
     putchar('1');
   }else {
     putchar('0');
   }
    bitChar<<=1;
   

  }
printf("\n");

printf("Number of ones: %d\n",numOfOnes);

//if the number of ones is even, append 1 to the most left bit
char newInput = inputChar;
if(numOfOnes%2==0){
 char mask2 = 1<<sizeof(char)*BITS-1;
 newInput = inputChar|mask2;

}


//printout the Odd 1 parity character and its bit representation
printf("Odd 1 partiy for the character is : %u, Bit representation:",newInput);
for(i=1;i<=sizeof(char)*BITS;i++){
  
    if(newInput & mask){
     putchar('1');
   }else {
     putchar('0');
   }

  newInput<<=1;

  }
 printf("\n");

}//end of choice == 3 opeartion


/*user choice == 4*/
else if(choice == 4){

//save the input
int input;
printf("Enter an integer to filter:");
scanf(" %u",&input);
printf("You entered:%u,Bit representation:",input);

//printout the bit representation of the input
unsigned int inputBit = input;
for(i=1;i<=sizeof(int)*BITS;i++){
  
  if(inputBit & mask){
     putchar('1');
   }else {
     putchar('0');
   }
    inputBit<<=1;
   if(!(i%8)){
      putchar(' ');
    }

  }
printf("\n");

//The filtering process

int userInput = BITS;
while(userInput!=0){

printf("Enter which bit you want to mute(enter 0 to quit):");
scanf(" %u",&userInput);

if(userInput>32||userInput<0){
printf("Invaild bit,try agian!\n");
continue;
}

else if(userInput==0){
break;
}

else{



int mute_mask = 1<<sizeof(char)*userInput-1;

input = input ^ mute_mask;



//printout the value and its new bit representation
printf("The new value is : %u,Bit representation: ",input);
unsigned int newInputBit = input;


for(i=1;i<=sizeof(int)*BITS;i++){
  
  if(newInputBit & mask){
     putchar('1');
   }else {
     putchar('0');
   }
    newInputBit<<=1;
   if(!(i%8)){
      putchar(' ');
    }

  }
}
printf("\n");
 
}





}//end of choice 4



else if(choice>4){
printf("invaild input,try again\n");
}

printf("Enter r to repeat,and anything to quit:");
scanf(" %c",&repeat);
printf("--------------------------------------\n");


}

 
   return 0;
}

