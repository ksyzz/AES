#include <stdio.h>
#include <rpcndr.h>

int** aes(int [4][4], int[4][4]);
void subBytes(int [4][4]);
void shiftRows(int [4][4]);
void mixColumns(int [4][4]);
void addRoundKey(int [4][4], int[4][4]);
int aes_multiple(int);
void keyExpansion(int key[16], int w[11][4][4]);
int** getS_Box();

int S_BOX[16][16];
int RC[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
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
        a[0][i] = aes_multiple(temp0) ^ (temp1 ^ aes_multiple(temp1)) ^ temp2 ^ temp3;
        a[1][i] = temp0 ^ (aes_multiple(temp1)) ^ (temp2 ^ aes_multiple(temp2)) ^ temp3;
        a[2][i] = temp0 ^ temp1 ^ (aes_multiple(temp2)) ^ (temp3 ^ aes_multiple(temp3));
        a[3][i] = temp0 ^ (aes_multiple(temp0)) ^ temp1 ^ temp2 ^ aes_multiple(temp3);
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

void keyExpansion(int key[16], int w[11][4][4]){
    for (int i = 0; i < 4; ++i) {
        w[0][i] =  {key[4*i], key[4*i+1], key[4*i+2], key[4*i+3]};
    }
    for (int i = 1; i < 11; i++){
        for (int j = 0; j < 4; ++j) {
            if (j == 0){

            } else{

            }
        }
    }
}

int** getS_Box(){

}