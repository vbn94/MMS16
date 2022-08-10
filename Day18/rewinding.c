#include <stdio.h>

int main(){
    FILE* fnames = fopen("names", "r");
    int sym;
    while ((sym = fgetc(fnames)) != EOF){
        putchar(sym);
    }
    rewind(fnames);
    while ((sym = fgetc(fnames)) != EOF){
        putchar(sym);
    }
    rewind(fnames);
    // fseek(fnames, 0L, SEEK_SET);
    while ((sym = fgetc(fnames)) != EOF){
        putchar(sym);
    }
    fclose(fnames);
    return 0;
}