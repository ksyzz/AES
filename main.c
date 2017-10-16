#include <stdio.h>
#include <rpcndr.h>

int** aes(int [4][4], int[4][4]);
void subBytes(int [4][4]);
void shiftRows(int [4][4]);
void mixColumns(int [4][4]);
void addRoundKey(int [4][4], int[4][4]);
int ase_multiple(int);
void keyExpansion(byte key[16], byte w[11][4]);
int** getS_Box();
int S_BOX[16][16];
int main(){
    int a[4] = {1, 2, 3, 4};
    printf("Hello, World! %d\n", a[0]);
    return 0;
}


int** aes(int content[4][4],  int password[4][4]){

}

void subBytes(int a[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int temp = a[i][j];
            int row = temp / 16;
            int column = temp % 16;
            a[i][j] = S_BOX[row][column];
        }
    }
}

void shiftRows(int a[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = a[i][2];
            a[i][2] = a[i][3];
            a[i][3] = temp;
        }
    }
}

void mixColumns(int a[4][4]){
    for (int i = 0; i < 4; ++i) {
        int temp0 = a[0][i];
        int temp1 = a[1][i];
        int temp2 = a[2][i];
        int temp3 = a[3][i];
        a[0][i] = ase_multiple(temp0) ^ (temp1 ^ ase_multiple(temp1)) ^ temp2 ^ temp3;
        a[1][i] = temp0 ^ (ase_multiple(temp1)) ^ (temp2 ^ ase_multiple(temp2)) ^ temp3;
        a[2][i] = temp0 ^ temp1 ^ (aes_multiple(temp2)) ^ (temp3 ^ aes_multiple(temp3));
        a[3][i] = temp0 ^ (aes_multiple(temp0)) ^ temp1 ^ temp2 ^ ase_multiple(temp3);
    }
}

void addRoundKey(int a[4][4], int p[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = a[i][j] ^ p[i][j];
        }
    }
}

int aes_multiple(int a){
    int b = a<<1;
    if (a < 128){
        return b % 256;
    } else{
        return (b ^ 0x1b) % 256;
    }
}

int** getS_Box(){

}