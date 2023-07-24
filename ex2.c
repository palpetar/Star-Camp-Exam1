#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t* mask);
void mirrorBits(uint64_t* mask);
int checkBit(uint64_t mask, int bit);
void printBits(uint64_t mask);
uint64_t removeBit(uint64_t mask, int bit);
uint64_t setBit(uint64_t mask, int bit);

int main(void){
    // Code does not work
    uint64_t mask1 = 0b0000011;
    uint32_t mask2 = 0b0001;
    uint16_t mask3 = 0b001;
    uint8_t mask4 = 0b001;
    printf("%d\n", onesCount(mask1, mask2, mask3, mask4));
    printBits(mask1);
    flipOddBits(&mask1);
    printBits(mask1);

}

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    int counter = 0;
    for(int i = 0; i < 64; i++){
        if(mask1 & (1 << i)){
            counter++;
        }
    }
    for(int i = 0; i < 32; i++){
        if(mask2 & (1 << i)){
            counter++;
        }
    }
    for(int i = 0; i < 16; i++){
        if(mask3 & (1 << i)){
            counter++;
        }
    }
    for(int i = 0; i < 8; i++){
        if(mask4 & (1 << i)){
            counter++;
        }
    }
    return counter;
}

void flipOddBits(uint64_t* mask){
    for(int i = 1; i < 64; i += 2){
        if(checkBit(*mask, i) == 1){
            removeBit(*mask, i);
        } else {
            setBit(*mask, i);
        }
    }
}

void mirrorBits(uint64_t* mask){

}

void printBits(uint64_t mask){
    for (int i = 64; i >= 0; i--) {
        printf("%d", checkBit(mask, i));
    }
    printf("\n");
}

uint64_t removeBit(uint64_t mask, int bit){
    return mask & ~(1 << bit);
}

uint64_t setBit(uint64_t mask, int bit){
    return mask | (1 << bit);
}

int checkBit(uint64_t mask, int bit){
    return (mask & (1 << bit)) ? 1 : 0;
}

