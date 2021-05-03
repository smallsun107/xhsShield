//
// Created by smallsun on 2021/4/17.
//

#include <cstring>
#include <cstdio>
#include "xyMd5.h"

typedef unsigned int uint;
template<class T> T __ROR4__(T value, uint count)
{
    return (value << (0x20 - count)) | (value >> count);
}

typedef struct {
    int buffer[348];
}MD5_CTX;

unsigned char k[256] = {
        0x78, 0xA4, 0x6A, 0xD7, 0x56, 0xB7, 0xC7, 0xE8, 0xDB, 0x70, 0x20, 0x24, 0xEE, 0xCE, 0xBD, 0xC1,
        0xAF, 0x0F, 0x7C, 0xF5, 0x2A, 0xC6, 0x87, 0x47, 0x13, 0x46, 0x30, 0xA8, 0x01, 0x95, 0x46, 0xFD,
        0xD8, 0x98, 0x80, 0x69, 0xAF, 0xF7, 0x44, 0x8B, 0xB1, 0x5B, 0xFF, 0xFF, 0xBE, 0xD7, 0x5C, 0x89,
        0x22, 0x11, 0x90, 0x6B, 0x93, 0x71, 0x98, 0xFD, 0x8E, 0x43, 0x79, 0xA6, 0x21, 0x08, 0xB4, 0x49,
        0x62, 0x25, 0x1E, 0xF6, 0x40, 0xB3, 0x40, 0xC0, 0x51, 0x5A, 0x5E, 0x26, 0xAA, 0xC7, 0xB6, 0xE9,
        0x5D, 0x10, 0x2F, 0xD6, 0x53, 0x14, 0x44, 0x02, 0x81, 0xE6, 0xA1, 0xD8, 0xC8, 0xFB, 0xD3, 0xE7,
        0xE6, 0xCD, 0xE1, 0x21, 0xD6, 0x07, 0x37, 0xC3, 0x87, 0x0D, 0xD5, 0xF4, 0xED, 0x14, 0x5A, 0x45,
        0x05, 0xE9, 0xE3, 0xA9, 0xF8, 0xA3, 0xEF, 0xFC, 0xD9, 0x02, 0x6F, 0x67, 0x8A, 0x4C, 0x2A, 0x8D,
        0x42, 0x39, 0xFA, 0xFF, 0x81, 0xF6, 0x71, 0x87, 0x22, 0x61, 0x9D, 0x6D, 0x0C, 0x38, 0xE5, 0xFD,
        0x44, 0xEA, 0xBE, 0xA4, 0xA9, 0xCF, 0xDE, 0x4B, 0x60, 0x4B, 0xBB, 0xF6, 0x70, 0xBC, 0xBF, 0xBE,
        0xC6, 0x7E, 0x9B, 0x28, 0xFA, 0x27, 0xA1, 0xEA, 0x85, 0x30, 0xEF, 0xD4, 0x05, 0x1D, 0x88, 0x04,
        0x39, 0xD0, 0xD4, 0xD9, 0xE5, 0x99, 0xDB, 0xE6, 0xF8, 0x7C, 0xA2, 0x1F, 0x65, 0x56, 0xAC, 0xC4,
        0x44, 0x22, 0x29, 0xF4, 0x97, 0xFF, 0x2A, 0x43, 0xA7, 0x23, 0x94, 0xAB, 0x39, 0xA0, 0x93, 0xFC,
        0xC3, 0x59, 0x5B, 0x65, 0x92, 0xCC, 0x0C, 0x8F, 0x7D, 0xF4, 0xEF, 0xFF, 0xD1, 0x5D, 0x84, 0x85,
        0x4F, 0x7E, 0xA8, 0x6F, 0xE0, 0xE6, 0x2C, 0xFE, 0x14, 0x43, 0x01, 0xA3, 0xA1, 0x11, 0x08, 0x4E,
        0x82, 0x7E, 0x53, 0xF7, 0x35, 0xF2, 0x3A, 0xBD, 0xBB, 0xD2, 0xD7, 0x2A, 0x91, 0xD3, 0x86, 0xEB
};


int MD5Init(MD5_CTX* ctx) {

    ctx->buffer[0] = 0x10325476;
    ctx->buffer[1] = 0x98BADCFE;
    ctx->buffer[2] = 0xEFCDAB89;
    ctx->buffer[3] = 0x67452301;
    memcpy(&(ctx->buffer[23]), k, 256);

}

int MD5Transform(MD5_CTX* ctx,unsigned char* in,int len) {

    unsigned int r0 = 0;
    unsigned int var_2C = 0;
    unsigned int var_30 = 0;
    unsigned int var_34 = 0;
    unsigned int var_38 = 0;
    unsigned int var_1C = 0;
    unsigned int var_24 = 0;
    unsigned int var_28 = 0;
    unsigned int var_3C = 0;
    unsigned int var_40 = 0;
    unsigned int var_44 = 0;
    unsigned int var_48 = 0;
    unsigned int var_20 = 0;
    unsigned int var_4C = 0;
    unsigned int var_50 = 0;
    unsigned int var_54 = 0;
    unsigned int var_58 = 0;
    unsigned int var_5C = 0;
    unsigned int var_60 = 0;
    unsigned int var_64 = 0;
    unsigned int var_68 = 0;
    unsigned int var_6C = 0;
    unsigned int var_204 = len;

    while (true) {
        int res = var_204--;
        if (!res) {
            break;
        }
        int a = ctx->buffer[0];
        int b = ctx->buffer[1];
        int c = ctx->buffer[2];
        int d = ctx->buffer[3];

        var_2C = in[0] | (in[1] << 0x8);
        var_2C = var_2C | (in[2] << 0x10);
        var_2C = var_2C | (in[3] << 0x18);
        var_30 = var_2C;

        var_2C = in[4] | (in[5] << 0x8);
        var_2C = var_2C | (in[6] << 0x10);
        var_2C = var_2C | (in[7] << 0x18);
        var_34 = var_2C;
        var_1C = __ROR4__((ctx->buffer[23] + var_30) + (((c ^ d) & b) ^ d) + a,26) + b;

        var_2C = in[8] | (in[9] << 0x8);
        var_2C = var_2C | (in[10] << 0x10);
        var_2C = var_2C | (in[11] << 0x18);
        var_38 = var_2C;
        var_28 = __ROR4__((var_34 + ctx->buffer[24]) + (((b ^ c) & var_1C) ^ c) + d,19);

        var_28 = var_1C + var_28;
        var_2C = in[12] | (in[13] << 0x8);
        var_2C = var_2C | (in[14] << 0x10);
        var_2C = var_2C | (in[15] << 0x18);
        var_3C = var_2C;
        var_24 = __ROR4__((var_38 + ctx->buffer[25]) + (((var_1C ^ b) & var_28) ^ b) + c,15);

        var_24 = var_28 + var_24;
        var_2C = in[16] | (in[17] << 0x8);
        var_2C = var_2C | (in[18] << 0x10);
        var_2C = var_2C | (in[19] << 0x18);
        var_40 = var_2C;
        var_20 = __ROR4__((var_3C + ctx->buffer[26]) + (((var_28 ^ var_1C) & var_24) ^ var_1C) + b,11);

        var_20 = var_24 + var_20;
        var_2C = in[20] | (in[21] << 0x8);
        var_2C = var_2C | (in[22] << 0x10);
        var_2C = var_2C | (in[23] << 0x18);
        var_44 = var_2C;
        var_1C = __ROR4__((var_40 + ctx->buffer[27]) + (((var_24 ^ var_28) & var_20) ^ var_28) + var_1C,25) + var_20;

        var_2C = in[24] | (in[25] << 0x8);
        var_2C = var_2C | (in[26] << 0x10);
        var_2C = var_2C | (in[27] << 0x18);
        var_48 = var_2C;
        var_28 = __ROR4__((var_44 + ctx->buffer[28]) + (((var_20 ^ var_24) & var_1C) ^ var_24) + var_28,20);
        var_28 = var_1C + var_28;

        var_2C = in[28] | (in[29] << 0x8);
        var_2C = var_2C | (in[30] << 0x10);
        var_2C = var_2C | (in[31] << 0x18);
        var_4C = var_2C;
        var_24 = __ROR4__((var_48 + ctx->buffer[29]) + (((var_1C ^ var_20) & var_28) ^ var_20) + var_24,15);
        var_24 = var_28 + var_24;

        var_2C = in[32] | (in[33] << 0x8);
        var_2C = var_2C | (in[34] << 0x10);
        var_2C = var_2C | (in[35] << 0x18);
        var_50 = var_2C;
        var_20 = __ROR4__((var_4C + ctx->buffer[30]) + (((var_28 ^ var_1C) & var_24) ^ var_1C) + var_20,12);
        var_20 = var_24 + var_20;

        var_2C = in[36] | (in[37] << 0x8);
        var_2C = var_2C | (in[38] << 0x10);
        var_2C = var_2C | (in[39] << 0x18);
        var_54 = var_2C;
        var_1C = __ROR4__((var_50 + ctx->buffer[31] + (((var_24 ^ var_28) & var_20) ^ var_28)) + var_1C,25);
        var_1C = var_20 + var_1C;


        var_2C = in[40] | (in[41] << 0x8);
        var_2C = var_2C | (in[42] << 0x10);
        var_2C = var_2C | (in[43] << 0x18);
        var_58 = var_2C;
        var_28 = __ROR4__((var_54 + ctx->buffer[32]) + (((var_20 ^ var_24) & var_1C) ^ var_24) + var_28,20);
        var_28 = var_1C + var_28;

        var_2C = in[44] | (in[45] << 0x8);
        var_2C = var_2C | (in[46] << 0x10);
        var_2C = var_2C | (in[47] << 0x18);
        var_5C = var_2C;
        var_24 = __ROR4__((var_58 + ctx->buffer[33]) + (((var_1C ^ var_20) & var_28) ^ var_20) + var_24,16);
        var_24 = var_28 + var_24;

        var_2C = in[48] | (in[49] << 0x8);
        var_2C = var_2C | (in[50] << 0x10);
        var_2C = var_2C | (in[51] << 0x18);
        var_60 = var_2C;
        var_20 = __ROR4__((var_5C + ctx->buffer[34]) + (((var_28 ^ var_1C) & var_24) ^ var_1C) + var_20,10);
        var_20 = var_24 + var_20;

        var_2C = in[52] | (in[53] << 0x8);
        var_2C = var_2C | (in[54] << 0x10);
        var_2C = var_2C | (in[55] << 0x18);
        var_64 = var_2C;
        var_1C = __ROR4__((var_60 + ctx->buffer[35]) + (((var_24 ^ var_28) & var_20) ^ var_28) + var_1C,25);
        var_1C = var_20 + var_1C;


        var_2C = in[56] | (in[57] << 0x8);
        var_2C = var_2C | (in[58] << 0x10);
        var_2C = var_2C | (in[59] << 0x18);
        var_68 = var_2C;
        var_28 = __ROR4__((var_64 + ctx->buffer[36]) + (((var_20 ^ var_24) & var_1C) ^ var_24) + var_28,19);
        var_28 = var_1C + var_28;


        var_2C = in[60] | (in[61] << 0x8);
        var_2C = var_2C | (in[62] << 0x10);
        var_2C = var_2C | (in[63] << 0x18);
        var_6C = var_2C;
        var_24 = __ROR4__((var_68 + ctx->buffer[37]) + (((var_1C ^ var_20) & var_28) ^ var_20) + var_24,15);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_6C + ctx->buffer[38]) + (((var_28 ^ var_1C) & var_24) ^ var_1C) + var_20,10);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_34 + (ctx->buffer[39] & 0xFF00FF00)) + (((var_20 ^ var_24) & var_28) ^ var_24) + var_1C,27);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_48 + ctx->buffer[40]) + (((var_1C ^ var_20) & var_24) ^ var_20) + var_28,23);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_5C + ctx->buffer[41]) + (((var_28 ^ var_1C) & var_20) ^ var_1C) + var_24,18);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_30 + (ctx->buffer[42] & 0xFF0011FF)) + (((var_24 ^ var_28) & var_1C) ^ var_28) + var_20,12);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_44 + ctx->buffer[43]) + (((var_20 ^ var_24) & var_28) ^ var_24) + var_1C,27);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_58 + ctx->buffer[44]) + (((var_1C ^ var_20) & var_24) ^ var_20) + var_28,23);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_6C + ctx->buffer[45]) + (((var_28 ^ var_1C) & var_20) ^ var_1C) + var_24,18);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_40 + ctx->buffer[46]) + (((var_24 ^ var_28) & var_1C) ^ var_28) + var_20,12);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_54 + ctx->buffer[47]) + (((var_20 ^ var_24) & var_28) ^ var_24) + var_1C,27);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_68 + ctx->buffer[48]) + (((var_1C ^ var_20) & var_24) ^ var_20) + var_28,23);
        var_28 = var_1C + var_28;

        var_24 =__ROR4__((var_3C + ctx->buffer[49]) + (((var_28 ^ var_1C) & var_20) ^ var_1C) + var_24,18);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_50 + ctx->buffer[50]) + (((var_24 ^ var_28) & var_1C) ^ var_28) + var_20,12);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_64 + ctx->buffer[51]) + (((var_20 ^ var_24) & var_28) ^ var_24) + var_1C,27);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_38 + (ctx->buffer[52] & 0xFF110011)) + (((var_1C ^ var_20) & var_24) ^ var_20) + var_28,23);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_4C + ctx->buffer[53]) + (((var_28 ^ var_1C) & var_20) ^ var_1C) + var_24,18);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_60 + ctx->buffer[54]) + (((var_24 ^ var_28) & var_1C) ^ var_28) + var_20,12);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_44 + ctx->buffer[55]) + (((var_20 ^ var_24) ^ var_28) + var_1C),28);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_50 + ctx->buffer[56]) + (((var_1C ^ var_20) ^ var_24) + var_28),21);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_5C + ctx->buffer[57]) + (((var_28 ^ var_1C) ^ var_20) + var_24),16);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_68 + ctx->buffer[58]) + (((var_24 ^ var_28) ^ var_1C) + var_20),9);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_34 + ctx->buffer[59]) + (((var_20 ^ var_24) ^ var_28) + var_1C),28);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_40 + ctx->buffer[60]) + (((var_1C ^ var_20) ^ var_24) + var_28),21);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_4C + ctx->buffer[61]) + (((var_28 ^ var_1C) ^ var_20) + var_24),16);
        var_24 = var_28 + var_24;

        var_1C = __ROR4__((var_64 + ctx->buffer[63]) + (((var_20 ^ var_24) ^ var_28) + var_1C),28);
        var_1C = var_20 + var_1C;

        var_20 = __ROR4__((var_58 + ctx->buffer[62]) + (((var_24 ^ var_28) ^ var_1C) + var_20),9);
        var_20 = var_24 + var_20;

        var_24 = __ROR4__((var_3C + ctx->buffer[65]) + (((var_28 ^ var_1C) ^ var_20) + var_24),16);
        var_24 = var_28 + var_24;

        var_28 = __ROR4__((var_30 + ctx->buffer[64]) + (((var_1C ^ var_20) ^ var_24) + var_28),21);
        var_28 = var_1C + var_28;

        var_20 = __ROR4__((var_48 + ctx->buffer[66]) + (((var_24 ^ var_28) ^ var_1C) + var_20),9);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_54 + ctx->buffer[67]) + (((var_20 ^ var_24) ^ var_28) + var_1C),28);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_60 + ctx->buffer[68]) + (((var_1C ^ var_20) ^ var_24) + var_28),21);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_6C + ctx->buffer[69]) + (((var_28 ^ var_1C) ^ var_20) + var_24),16);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_38 + ctx->buffer[70]) + (((var_24 ^ var_28) ^ var_1C) + var_20),9);
        var_20 = var_24 + var_20;

        // orn 或非操作
        // bic 与非操作
        var_1C = __ROR4__((var_30 + ctx->buffer[71]) + (((var_20 |~ var_28) ^ var_24) + var_1C),26);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_4C + ctx->buffer[72]) + (((var_1C |~ var_24) ^ var_20) + var_28),22);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_68 + ctx->buffer[73]) + (((var_28 |~ var_20) ^ var_1C) + var_24),17);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_44 + ctx->buffer[74]) + (((var_24 |~ var_1C) ^ var_28) + var_20),11);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_60 + ctx->buffer[75]) + (((var_20 |~ var_28) ^ var_24) + var_1C),26);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_3C + ctx->buffer[76]) + (((var_1C |~ var_24) ^ var_20) + var_28),22);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_58 + ctx->buffer[77]) + (((var_28 |~ var_20) ^ var_1C) + var_24),17);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_34 + ctx->buffer[78]) + (((var_24 |~ var_1C) ^ var_28) + var_20),11);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_50 + ctx->buffer[79]) + (((var_20 |~ var_28) ^ var_24) + var_1C),26);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_6C + ctx->buffer[80]) + (((var_1C |~ var_24) ^ var_20) + var_28),22);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_48 + ctx->buffer[81]) + (((var_28 |~ var_20) ^ var_1C) + var_24),17);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_64 + ctx->buffer[82]) + (((var_24 |~ var_1C) ^ var_28) + var_20),11);
        var_20 = var_24 + var_20;

        var_1C = __ROR4__((var_40 + ctx->buffer[83]) + (((var_20 |~ var_28) ^ var_24) + var_1C),26);
        var_1C = var_20 + var_1C;

        var_28 = __ROR4__((var_5C + ctx->buffer[84]) + (((var_1C |~ var_24) ^ var_20) + var_28),22);
        var_28 = var_1C + var_28;

        var_24 = __ROR4__((var_38 + ctx->buffer[85]) + (((var_28 |~ var_20) ^ var_1C) + var_24),17);
        var_24 = var_28 + var_24;

        var_20 = __ROR4__((var_54 + ctx->buffer[86]) + (((var_24 |~ var_1C) ^ var_28) + var_20),11);
        var_20 = var_24 + var_20;

        ctx->buffer[0] = ctx->buffer[0] + var_1C;
        ctx->buffer[1] = ctx->buffer[1] + var_20;
        ctx->buffer[2] = ctx->buffer[2] + var_24;
        ctx->buffer[3] = ctx->buffer[3] + var_28;
        in += 64;

        for (int i = 0; i < 4; ++i) {
            printf("%02x ",ctx->buffer[i]);
        }
        printf("\r\n");

    }

    for (int i = 0; i < 4; ++i) {
        printf("%02x ",ctx->buffer[i]);
    }

}


int MD5Update(MD5_CTX* ctx,unsigned char* in,unsigned int length) {

    unsigned int count0 = 0;
    unsigned int count1 = 0;
    unsigned int partlen = 0;

    if (length != 0) {

        count0 = ctx->buffer[4] + (length << 0x3); //bits数
        if (count0 < ctx->buffer[4]) {
            ctx->buffer[5] += 1;
        }

        ctx->buffer[5] = ctx->buffer[5] + (length >> 29);
        ctx->buffer[4] = count0;

        partlen = ctx->buffer[22];
        if (partlen == 0) {
            partlen = length >> 0x6;
            if (partlen == 0) {
                //保存剩余长度
                ctx->buffer[22] = length;
                memcpy(&ctx->buffer[6],in,length);
                return 1;
            }
            MD5Transform(ctx,in,partlen);
            partlen = partlen << 0x6;
            // 加上原始长度 移到in尾部
            length = length - partlen;
            if (length == 0) {
                return 1;
            }
            ctx->buffer[22] = length;
            memcpy(&ctx->buffer[6],in + partlen,length);
            return 1;
        }

    //    unsigned int var_20 = ctx->state[6];
    //    if (length > 0x3F) {
    //        //memcpy();
    //        //MD5Transform();
    //    }
    //
    //    if (length > 0x40) {
    //        //memcpy();
    //    }

    }

    return 1;
}


void xyMd5::GenrateResult(unsigned char* url,char* out) {

    unsigned char aesDecode[64] = {
            0x96, 0x9A, 0x84, 0x5B, 0x29, 0xA7, 0x51, 0x56, 0x4A, 0x0D, 0x47, 0x24, 0x29, 0x02, 0x25, 0x6C,
            0x9E, 0x46, 0xE2, 0xDB, 0xE2, 0x89, 0xC7, 0x64, 0x0F, 0x57, 0xE5, 0x57, 0x80, 0xC1, 0xCD, 0xD5,
            0x46, 0x4E, 0x38, 0x92, 0xA6, 0xDC, 0x18, 0x69, 0x90, 0xF8, 0x85, 0xD7, 0xED, 0xDB, 0xAD, 0x0A,
            0xFC, 0x2C, 0x43, 0x8F, 0x44, 0x19, 0xCD, 0xA3, 0xFA, 0xF2, 0x39, 0x82, 0xAB, 0x8F, 0x09, 0xE2
    };
    unsigned char xor36[64] = {0};
    unsigned char xor5c[64] = {0};
    unsigned int remainLen = 0;
    MD5_CTX ctx;
    MD5_CTX ctx1;
    MD5Init(&ctx);
    MD5Init(&ctx1);

    for (int i = 0; i < 64; ++i) {
        xor36[i] = aesDecode[i] ^ 0x36;
    }

    for (int i = 0; i < 64; ++i) {
        xor5c[i] = aesDecode[i] ^ 0x5c;
    }

    MD5Update(&ctx,xor36, 64);

    MD5Update(&ctx1,xor5c, 64);

    // 用xor36的 ctx
    // 读取请求内容
    MD5Update(&ctx, url, strlen(reinterpret_cast<const char *>(url)));

    remainLen = ctx.buffer[22];
    // 剩余数据尾部写入0x80写入一字节
    *((unsigned char*)(ctx.buffer) + 24 + remainLen) = 0x80;;
    remainLen += 1;

//    if (remainLen >= 0x39) {
//        //MD5Transform(&ctx, reinterpret_cast<unsigned char *>(ctx.state[6]), 1);
//    }

    // 保存ctx.state[4]的八字节到这里
    ctx.buffer[6 + 0x38 / 4] = ctx.buffer[4];
    MD5Transform(&ctx, reinterpret_cast<unsigned char *>(&ctx.buffer[6]), 1);
    ctx.buffer[22] = 0;
    memset(&ctx.buffer[6],0,0x40);

    /*开始用ctx1*/

    // 用xor5c的ctx 对上一步的数据进行计算
    MD5Update(&ctx1, reinterpret_cast<unsigned char *>(&ctx.buffer[0]), 16);

    remainLen = ctx1.buffer[22];
    ctx1.buffer[6 + remainLen / 4] = 0x80;
    remainLen += 1;
    // 保存ctx.state[4]的八字节到这里
    ctx1.buffer[6 + 0x38 / 4] = ctx1.buffer[4];
    MD5Transform(&ctx1, reinterpret_cast<unsigned char *>(&ctx1.buffer[6]), 1);
    ctx1.buffer[22] = 0;
    memset(&ctx1.buffer[6],0,0x40);

    memcpy(out,(unsigned char*)(ctx1.buffer),16);

}
