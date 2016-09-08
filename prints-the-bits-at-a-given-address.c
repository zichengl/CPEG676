#include <stdio.h>
#include <math.h>

void show_bits(void* start, int n_bits){
    int i;
   if (n_bits > 8){
	printf("passing value of %d size is %d\n", * (int *)start, sizeof(*(int *) start));
	int n = *(int *)start;
	for ( i = 0;i < n_bits;i++){
		int reminder = n % 2;
		 n = n / 2;
		printf("%d",reminder);
	}
       printf("\n");
   }
   else{
   	printf("passing value of %d size is %d\n",* (char *)start, sizeof(*(char *) start));
   	int n = *(char *)start;
   	for (i = 0; i < n_bits; i++){
   		int reminder = n % 2;
   		n = n / 2;
        printf("%d",reminder);
        }
       printf("\n");
	
   }

};

int main(void) {
    // Disable stdout buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    
    int x=1025;
    show_bits( (void*) &x, 11);
    printf("should have shown\n10000000001\n\n");
    char y=10;
    show_bits( (void*) &y, 8);
    printf("should have shown\n01010000\n\n");
    char z='A';
    show_bits( (void*) &z, 8);
    printf("should have shown\n10000010\n");
    
    fflush(stdout);
    usleep(1);
    return 0;
}
