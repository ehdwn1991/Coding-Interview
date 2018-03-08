#include <stdio.h>

int gcd_minus();
int gcd_modulus();
int gcd_recursion();
int main(){
    
    int u, v;

    puts("\n ECLID1 : Get GCD of two positive integer"
        "\n             Input 0 to end program");

    while (1){
        puts("\n\n Input two positive integer -> ");
        scanf("%d %d",&u,&v);
        if (u < 0 || v < 0)
            continue;
        if (u == 0 || v == 0)
            break;
        
        printf("\n   GCO_MINUS of %d and %d is %d.", u, v, gcd_minus(u, v));
        printf("\n   GCO_MODULUS of %d and %d is %d.", u, v, gcd_modulus(u, v));
        printf("\n   GCO_RECURSION of %d and %d is %d.", u, v, gcd_recursion(u, v));
    }

}

int gcd_minus(int u, int v){
    
    int t;
    while (u){
        if (u < v){
            t = u; u = v; v = t;
        }
        u = u - v;
    }
    return v;
}

int gcd_modulus(int u, int v){
    
    int t;
    while (v){
        t = u%v;
        u = v;
        v = t;
    }
    return u;
}


int gcd_recursion(int u, int v){
    
    if (v == 0){
        return u;
    }
    else{
        return gcd_recursion(v, u%v);
    }
}

