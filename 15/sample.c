#include <stdio.h>

int main(){
    int abflag = 0;
    int A,B,X,Y,Z;
    for(A=0;A<10;A++){
        for(B=0;B<10;B++){
            if(A!=B){
                if((A + A) % 10 == B){
                    X = 100 * B + 10 * A + A;
                    Y = 10 * B + A;
                    Z = 100 * A + 10 * B + B;
                    if(Z == X + Y){
                        printf("(A,B) == (%d,%d)\n",A,B);
                        abflag=1;
                        break;
                    }
                }
            }
            if(abflag == 1) break;
        }
    }
    return 0;
}