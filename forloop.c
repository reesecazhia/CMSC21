//iterative statements

//for loop syntax
//for (initialization; condition; variable_update){
		//code_block_here	
//}

#include <stdio.h>

int main (){
	int i = 0;
	/* for (i=0; i<5; i++){
		printf("%d Hello World!\n", i+1);
	} */

	/*while(i<5){
		printf("%d Hello World! \n", i);
		i++;
	}*/

	do {
		printf("%d Hello World! \n", i);
		i++;
	} while (i<5);

	return 0; 
}