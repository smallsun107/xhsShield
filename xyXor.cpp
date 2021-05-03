//
// Created by smallsun on 2021/4/18.
//

#include <cstdio>
#include "xyXor.h"

void InitTable(unsigned int* array,unsigned int len) {

    unsigned char instr[14] = {
            0x73, 0x74, 0x64, 0x3A, 0x3A, 0x61, 0x62, 0x6F, 0x72, 0x74, 0x28, 0x29, 0x3B, 0x00
    };

    unsigned int r0 = 0;
    unsigned int var_1C = 0;
    unsigned int var_24 = 0;
    unsigned int var_20 = 0;


    for (int i = 0; i <= 0xFF; i++) {
        array[i] = i;
    }

    for (int i = 0; i <= 0xFF; i += 4) {

        var_1C = array[i];
        var_24 = (array[i] + instr[var_20] + var_24) & 0xFF;
        var_20 += 1;

        if (var_20 == len) {
            var_20 = 0;
        }
        array[i] = array[var_24];
        array[var_24] = var_1C;

        var_1C = array[i + 1];
        var_24 = (instr[var_20] + var_1C + var_24) & 0xFF;
        var_20 += 1;

        if (var_20 == len) {
            var_20 = 0;
        }

        array[i + 1] = array[var_24];
        array[var_24] = var_1C;

        var_1C = array[i + 2];
        var_24 = (instr[var_20] + var_1C + var_24) & 0xFF;
        var_20 += 1;

        if (var_20 == len) {
            var_20 = 0;
        }

        array[i + 2] = array[var_24];
        array[var_24] = var_1C;

        var_1C = array[i + 3];
        var_24 = (instr[var_20] + var_1C + var_24) & 0xFF;
        var_20 += 1;

        if (var_20 == len) {
            var_20 = 0;
        }

        array[i + 3] = array[var_24];
        array[var_24] = var_1C;

    }
    printf("Init end...\r\n");

}

void XorResult(unsigned int* table,unsigned char* in,unsigned int len,unsigned char* out) {

    unsigned int var_2C = 0;
    unsigned int var_30 = 0;
    unsigned int var_38 = 0;
    unsigned int var_34 = 0;
    unsigned int var_3C = 0;

    var_3C = len >> 0x3;

    while (var_3C != 0) {
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_34 + var_30) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[0] = table[(var_34 + var_38) & 0xFF] ^ in[0];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[1] = table[(var_34 + var_38) & 0xFF] ^ in[1];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[2] = table[(var_34 + var_38) & 0xFF] ^ in[2];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[3] = table[(var_34 + var_38) & 0xFF] ^ in[3];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[4] = table[(var_34 + var_38) & 0xFF] ^ in[4];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[5] = table[(var_34 + var_38) & 0xFF] ^ in[5];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[6] = table[(var_34 + var_38) & 0xFF] ^ in[6];
        var_2C = (var_2C + 1) & 0xFF;

        var_34 = table[var_2C];
        var_30 = (var_30 + var_34) & 0xFF;
        var_38 = table[var_30];
        table[var_2C] = var_38;
        table[var_30] = var_34;
        out[7] = table[(var_34 + var_38) & 0xFF] ^ in[7];
        //var_2C = (var_2C + 1) & 0xFF;

        in += 8;
        out += 8;
        var_3C -= 1;

    }

    var_3C = len & 7;
    var_2C = (var_2C + 1) & 0xFF;

    var_34 = table[var_2C];
    var_30 = (var_30 + var_34) & 0xFF;
    var_38 = table[var_30];
    table[var_2C] = var_38;
    table[var_30] = var_34;
    out[0] = table[(var_34 + var_38) & 0xFF] ^ in[0];
    var_3C = var_3C - 1;
    if (!var_3C) {
        return;
    }
    var_2C = (var_2C + 1) & 0xFF;


    var_34 = table[var_2C];
    var_30 = (var_30 + var_34) & 0xFF;
    var_38 = table[var_30];
    table[var_2C] = var_38;
    table[var_30] = var_34;
    out[1] = table[(var_34 + var_38) & 0xFF] ^ in[1];
    var_3C = var_3C - 1;
    if (!var_3C) {
        return;
    }
    var_2C = (var_2C + 1) & 0xFF;

    var_34 = table[var_2C];
    var_30 = (var_30 + var_34) & 0xFF;
    var_38 = table[var_30];
    table[var_2C] = var_38;
    table[var_30] = var_34;
    out[2] = table[(var_34 + var_38) & 0xFF] ^ in[2];
    var_3C = var_3C - 1;
    if (!var_3C) {
        return;
    }

    printf("XorResult end...\r\n");

}


void xyXor::GenrateResult(unsigned char* in, unsigned char *out) {
    unsigned int array[1024] = {0};
    InitTable(array,13);

    XorResult(array,in, 0x53, out);
}