

/*

	ASSUMPTION: each word is delimted by one and only one space. Also, no commas will be 
	used

*/

#include <stdio.h> 

int main() {

	char input[80];
	
	char *inputPointer = &input[0]; 
	
	//prompt message
	printf("Input a sentence: "); 
	
	
	
	int count = 0;
	//read all chars in the buffer placing them into the array until new line is encountered
	while( count < 80 && ( *(inputPointer + count++)  = getchar()) != '\n')
		; 
		
	//since the above loop inserts a newline char and then increments we must decrement
	//the count once to be at the position of the new line then once again so count is 
	//at the position just before the newline 	
	count -= 2;  
	
	//check if the char that count currently points to is a terminating char. If so,
	//decrement count again. 
	
	
	if(*(inputPointer + count) == 33 || *(inputPointer + count) == 46 || *(inputPointer + count)  == 63) 
		count--; 
	
	int end = count; //marks the end of the word 
	for(int start = count; start >= 0; start--) {
		
		
		
		if( *(inputPointer + start) == ' ') {
			//print the word starting at start + 1 and terminating at end 
			for(int index = (start + 1); index <= end; index++) {
				printf("%c", *(inputPointer + index) ); 
			}
			
			//print a space 
			printf(" "); 
			
			//move end index to the char just before the space found
			end = (start - 1); 
			
		}
		else if(start == 0) {
			//print the word starting at start and terminating at end 
			for(int index = start; index <= end; index++) {
				printf("%c", *(inputPointer + index)); 
			}
			
			//no need to print a space
			
			//no need to update end index 
		} 
		
	}
	
	//now print the terminating char for the sentence. This is the char directly after the
	//index pointed to by count. This should be newline or a terminating character. 
	printf("%c", *(inputPointer + (count + 1) ) ); 
	
	
}
