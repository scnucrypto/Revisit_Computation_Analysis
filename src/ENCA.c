#include "ENCA.h"

M8 invm = {
    .M[0] = 0x21,
    .M[1] = 0x76,
    .M[2] = 0x3b,
    .M[3] = 0x81,
    .M[4] = 0xd5,
    .M[5] = 0x25,
    .M[6] = 0x69,
    .M[7] = 0xb0
};
M8 non_invm = {
    .M[0] = 0xb6,
    .M[1] = 0x2f,
    .M[2] = 0xf3,
    .M[3] = 0x4b,
    .M[4] = 0xc6,
    .M[5] = 0x0b,
    .M[6] = 0x25,
    .M[7] = 0x4b
};
M8 invm_HW1 = {
    .M[0] = 0x3d,
    .M[1] = 0xda,
    .M[2] = 0x20,
    .M[3] = 0x76,
    .M[4] = 0x0b,
    .M[5] = 0x8a,
    .M[6] = 0x5e,
    .M[7] = 0xc0,
};
M8 non_invm_HW1 = {
    .M[0] = 0x6c,
    .M[1] = 0xd8,
    .M[2] = 0xe6,
    .M[3] = 0x0e,
    .M[4] = 0x08,
    .M[5] = 0x5d,
    .M[6] = 0xcc,
    .M[7] = 0xc5,
};
uint8_t identM8[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
uint8_t non8linear[256] =
{
	0xd6, 0x90, 0xe9, 0xfe, 0xcc, 0xe1, 0x3d, 0xb7,
	0x16, 0xb6, 0x14, 0xc2, 0x28, 0xfb, 0x2c, 0x05,
	0x2b, 0x67, 0x9a, 0x76, 0x2a, 0xbe, 0x04, 0xc3,
	0xaa, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99,
	0x9c, 0x42, 0x50, 0xf4, 0x91, 0xef, 0x98, 0x7a,
	0x33, 0x54, 0x0b, 0x43, 0xed, 0xcf, 0xac, 0x62,
	0xe4, 0xb3, 0x1c, 0xa9, 0xc9, 0x08, 0xe8, 0x95,
	0x80, 0xdf, 0x94, 0xfa, 0x75, 0x8f, 0x3f, 0xa6,
	0x47, 0x07, 0xa7, 0xfc, 0xf3, 0x73, 0x17, 0xba,
	0x83, 0x59, 0x3c, 0x19, 0xe6, 0x85, 0x4f, 0xa8,
	0x68, 0x6b, 0x81, 0xb2, 0x71, 0x64, 0xda, 0x8b,
	0xf8, 0xeb, 0x0f, 0x4b, 0x70, 0x56, 0x9d, 0x35,
	0x1e, 0x24, 0x0e, 0x5e, 0x63, 0x58, 0xd1, 0xa2,
	0x25, 0x22, 0x7c, 0x3b, 0x01, 0x21, 0x78, 0x87,
	0xd4, 0x00, 0x46, 0x57, 0x9f, 0xd3, 0x27, 0x52,
	0x4c, 0x36, 0x02, 0xe7, 0xa0, 0xc4, 0xc8, 0x9e,
	0xea, 0xbf, 0x8a, 0xd2, 0x40, 0xc7, 0x38, 0xb5,
	0xa3, 0xf7, 0xf2, 0xce, 0xf9, 0x61, 0x15, 0xa1,
	0xe0, 0xae, 0x5d, 0xa4, 0x9b, 0x34, 0x1a, 0x55,
	0xad, 0x93, 0x32, 0x30, 0xf5, 0x8c, 0xb1, 0xe3,
	0x1d, 0xf6, 0xe2, 0x2e, 0x82, 0x66, 0xca, 0x60,
	0xc0, 0x29, 0x23, 0xab, 0x0d, 0x53, 0x4e, 0x6f,
	0xd5, 0xdb, 0x37, 0x45, 0xde, 0xfd, 0x8e, 0x2f,
	0x03, 0xff, 0x6a, 0x72, 0x6d, 0x6c, 0x5b, 0x51,
	0x8d, 0x1b, 0xaf, 0x92, 0xbb, 0xdd, 0xbc, 0x7f,
	0x11, 0xd9, 0x5c, 0x41, 0x1f, 0x10, 0x5a, 0xd8,
	0x0a, 0xc1, 0x31, 0x88, 0xa5, 0xcd, 0x7b, 0xbd,
	0x2d, 0x74, 0xd0, 0x12, 0xb8, 0xe5, 0xb4, 0xb0,
	0x89, 0x69, 0x97, 0x4a, 0x0c, 0x96, 0x77, 0x7e,
	0x65, 0xb9, 0xf1, 0x09, 0xc5, 0x6e, 0xc6, 0x84,
	0x18, 0xf0, 0x7d, 0xec, 0x3a, 0xdc, 0x4d, 0x20,
	0x79, 0xee, 0x5f, 0x3e, 0xd7, 0xcb, 0x39, 0x48,
};
uint8_t non4linear1[16] = {0x01, 0x02, 0x0C, 0x05, 0x07, 0x08, 0x0A, 0x0F, 0x04, 0x0D, 0x0B, 0x0E, 0x09, 0x06, 0x00, 0x03};
uint8_t non4linear2[16] = {0x01, 0x02, 0x0C, 0x05, 0x07, 0x08, 0x0A, 0x0F, 0x04, 0x0D, 0x0B, 0x0E, 0x09, 0x06, 0x00, 0x03};
unsigned int rseed;

// generation of an invertible matrix without identity rows
void generate_invertible_mat()
{
    int while_flag = 1, HW_flag = 1;
    while(while_flag)
    {
        HW_flag = 1;
        randM8(&invm);
        if(isinvertM8(invm)) // invertible
        {   for(int i = 0; i < 8; i ++)
            {
                if(invm.M[i] == identM8[i]) 
                {
                    HW_flag = 0;
                    break;
                }
            }
            if(HW_flag) while_flag = 0;
        }
    }
}

// generation of an invertible matrix with at least one row whose HW=1
void generate_invertible_mat_HW1()
{
    int while_flag = 1;
    while(while_flag)
    {
        randM8(&invm_HW1);
        if(isinvertM8(invm_HW1)) // invertible
        {   for(int i = 0; i < 8; i ++)
            {
                if(invm_HW1.M[i] == identM8[i]) 
                {
                    while_flag = 0;
                    break;
                }
            }
        }
    }
}

// generation of an non-invertible matrix without identity rows
void generate_non_invertible_mat()
{
    int while_flag = 1, HW_flag = 1;
    while(while_flag)
    {
        HW_flag = 1;
        randM8(&non_invm);
        if(!isinvertM8(non_invm)) // non-invertible
        {   for(int i = 0; i < 8; i ++)
            {
                if(non_invm.M[i] == identM8[i]) 
                {
                    HW_flag = 0;
                    break;
                }
            }
            if(HW_flag) while_flag = 0;
        }
    }
}

// generation of an non-invertible matrix with at least one row whose HW=1
void generate_non_invertible_mat_HW1()
{
    int while_flag = 1;
    while(while_flag)
    {
        randM8(&non_invm_HW1);
        if(!isinvertM8(non_invm_HW1)) // invertible
        {   for(int i = 0; i < 8; i ++)
            {
                if(non_invm_HW1.M[i] == identM8[i]) 
                {
                    while_flag = 0;
                    break;
                }
            }
        }
    }
}

// generation of a random 4-bit permutation
void generate4Permutation(uint8_t *permutation)
{
	int i, j;
	uint8_t temp;
    InitRandom((rseed++) ^ ((unsigned int)time(NULL)));
	for (i = 0; i < 16; i++)
	{
		permutation[i] = i;
	}
	for (i = 0; i < 15; i++)
	{
		j = cus_random()%(16 - i);
		temp = permutation[i];
		permutation[i] = permutation[i+j];
		permutation[i + j] = temp;
	}
}

// generation of a random 8-bit permutation
void generate8Permutation(uint8_t *permutation)
{
	int i, j;
	uint8_t temp;
    InitRandom((rseed++) ^ ((unsigned int)time(NULL)));
	for (i = 0; i < 256; i++)
	{
		permutation[i] = i;
	}
	for (i = 0; i < 255; i++)
	{
		j = cus_random()%(256 - i);
		temp = permutation[i];
		permutation[i] = permutation[i + j];
		permutation[i + j] = temp;
	}
}

// generation of a random n-bit permutation
void generatePermutation(int bit, uint8_t *permutation)
{
    int con = 0x01 << bit;
    int i, j;
	uint8_t temp;
    InitRandom((rseed++) ^ ((unsigned int)time(NULL)));
	for (i = 0; i < con; i++)
	{
		permutation[i] = i;
	}
	for (i = 0; i < con - 1; i++)
	{
		j = cus_random()%(con - i);
		temp = permutation[i];
		permutation[i] = permutation[i + j];
		permutation[i + j] = temp;
	}
}

// generation of an 8-bit permutation with different algebraic degrees
void gen_8bit_bijection(int degree, uint8_t *permutation)
{
    if(degree == 1)
    {
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        for(int i = 0; i < 256; i++)
        {
            permutation[i] = MatMulNumM8(mat, i);
        }
    }
    if(degree == 2)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        uint8_t P1[8], P2[8], P3[4];
        generatePermutation(3, P1);
        generatePermutation(3, P2);
        generatePermutation(2, P3);
        for(int i = 0; i < 256; i++)
        {
            x = MatMulNumM8(mat, i);
            permutation[i] = (P1[(x >> 5) & 7] << 5) | (P2[(x >> 2) & 7] << 2) | P3[x & 3];
            permutation[i] = MatMulNumM8(mat_inv, permutation[i]);
        }
    }
    if(degree == 3)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        uint8_t P1[16], P2[16];
        generate4Permutation(P1);
        generate4Permutation(P2);
        for(int i = 0; i < 256; i++)
        {
            x = MatMulNumM8(mat, i);
            permutation[i] = (P1[x >> 4] << 4) | P2[x & 15];
            permutation[i] = MatMulNumM8(mat_inv, permutation[i]);
        }
    }
    if(degree == 4)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        uint8_t P1[0x01 << 5], P2[0x01 << 3];
        generatePermutation(5, P1);
        generatePermutation(3, P2);
        for(int i = 0; i < 256; i++)
        {
            x = MatMulNumM8(mat, i);
            permutation[i] = (P2[x >> 5] << 5) | P1[x & 31];
            permutation[i] = MatMulNumM8(mat_inv, permutation[i]);   
        }
    }
    if(degree == 5)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        uint8_t P1[0x01 << 6], P2[0x01 << 2];
        generatePermutation(6, P1);
        generatePermutation(2, P2);
        for(int i = 0; i < 256; i++)
        {
            x = MatMulNumM8(mat, i);
            permutation[i] = (P2[x >> 6] << 6) | P1[x & 63]; // permutation[i] = (P1[i >> 2] << 2) | P2[i & 3]; -> degree-2 
            permutation[i] = MatMulNumM8(mat_inv, permutation[i]);
        }
    }
    if(degree == 6)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        uint8_t P1[0x01 << 7], P2[0x01 << 1];
        generatePermutation(7, P1);
        generatePermutation(1, P2);
        for(int i = 0; i < 256; i++)
        {
            x = MatMulNumM8(mat, i);
            permutation[i] = (P2[x >> 7] << 7) | P1[x & 127]; // permutation[i] = (P1[i >> 1] << 1) | P2[i & 1]; -> degree-1
            permutation[i] = MatMulNumM8(mat_inv, permutation[i]);
        }
    }
    if(degree == 7)
    {
        uint8_t x;
        M8 mat, mat_inv;
        genMatpairM8(&mat, &mat_inv);
        generate8Permutation(permutation);
        for(int i = 0; i < 256; i++)
        {
            // permutation[i] = MatMulNumM8(mat, permutation[i]);
            permutation[i] = permutation[i];
        }
    }
}

// generation of different encodings
void generate_map(uint8_t map[256], int index)
{
    int x;
    uint8_t temp;

    // linear encoding = invertible matrix with HW > 1; nonlinear encoding = 4-bit permutation
    if(index == 1)
    {   
        generate_invertible_mat();
        generate4Permutation(non4linear1);
        generate4Permutation(non4linear2);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(invm, temp);
            map[x] = (non4linear1[temp >> 4] << 4) | (non4linear2[temp & 0xf]);
        }
    }

    // linear encoding = invertible matrix with HW = 1; nonlinear encoding = 4-bit permutation
    else if(index == 2)   
    {   
        generate_invertible_mat_HW1();
        generate4Permutation(non4linear1);
        generate4Permutation(non4linear2);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(invm_HW1, temp);
            map[x] = (non4linear1[temp >> 4] << 4) | (non4linear2[temp & 0xf]);
        }
    }

    // linear encoding = non-invertible matrix with HW > 1; nonlinear encoding = 4-bit permutation
    else if(index == 3)   
    {   
        generate_non_invertible_mat();
        generate4Permutation(non4linear1);
        generate4Permutation(non4linear2);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(non_invm, temp);
            map[x] = (non4linear1[temp >> 4] << 4) | (non4linear2[temp & 0xf]);
        }
    }

    // linear encoding = non-invertible matrix with HW = 1; nonlinear encoding = 4-bit permutation
    else if(index == 4)   
    {   
        generate_non_invertible_mat_HW1();
        generate4Permutation(non4linear1);
        generate4Permutation(non4linear2);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(non_invm_HW1, temp);
            map[x] = (non4linear1[temp >> 4] << 4) | (non4linear2[temp & 0xf]);
        }
    }

    // linear encoding = invertible matrix with HW > 1; nonlinear encoding = 8-bit permutation
    else if(index == 5)   
    {   
        generate_invertible_mat();
        generate8Permutation(non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(invm, temp);
            map[x] = non8linear[temp];
        }
    }

    // linear encoding = invertible matrix with HW = 1; nonlinear encoding = 8-bit permutation
    else if(index == 6)   
    {   
        generate_invertible_mat_HW1();
        generate8Permutation(non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(invm_HW1, temp);
            map[x] = non8linear[temp];
        }
    }

    // linear encoding = non-invertible matrix with HW > 1; nonlinear encoding = 8-bit permutation
    else if(index == 7)   
    {   
        generate_non_invertible_mat();
        generate8Permutation(non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(non_invm, temp);
            map[x] = non8linear[temp];
        }
    }

    // linear encoding = non-invertible matrix with HW = 1; nonlinear encoding = 8-bit permutation
    else if(index == 8)   
    {   
        generate_non_invertible_mat_HW1();
        generate8Permutation(non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            temp = MatMulNumM8(non_invm_HW1, temp);
            map[x] = non8linear[temp];
        }
    }

    // linear encoding = invertible matrix with HW > 1
    else if(index == 9)   
    {   
        generate_invertible_mat();
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = MatMulNumM8(invm, temp);
        }
    }

    // linear encoding = invertible matrix with HW = 1
    else if(index == 10)   
    {   
        generate_invertible_mat_HW1();
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = MatMulNumM8(invm_HW1, temp);
        }
    }

    // linear encoding = non-invertible matrix with HW > 1
    else if(index == 11)   
    {   
        generate_non_invertible_mat();
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = MatMulNumM8(non_invm, temp);
        }
    }

    // linear encoding = invertible matrix with HW = 1
    else if(index == 12)   
    {   
        generate_non_invertible_mat_HW1();
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = MatMulNumM8(non_invm_HW1, temp);
        }
    }

    // nonlinear encoding = 4-bit permutation
    else if(index == 13)   
    {   
        generate4Permutation(non4linear1);
        generate4Permutation(non4linear2);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = (non4linear1[temp >> 4] << 4) | (non4linear2[temp & 0xf]);
        }
    }

    // nonlinear encoding = 8-bit permutation
    else if(index == 14)
    {   
        generate8Permutation(non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }
}

void generate_map_degree(uint8_t map[256], int index) // generation of encodings with different algebraic degrees
{
    int x;
    uint8_t temp;

    // degree-1 8-bit encoding
    if(index == 1) 
    {
        gen_8bit_bijection(1, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-2 8-bit non-linear encoding
    else if(index == 2)
    {
        gen_8bit_bijection(2, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-3 8-bit non-linear encoding
    else if(index == 3)
    {
        gen_8bit_bijection(3, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-4 8-bit non-linear encoding
    else if(index == 4)
    {
        gen_8bit_bijection(4, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-5 8-bit non-linear encoding
    else if(index == 5)
    {
        gen_8bit_bijection(5, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-6 8-bit non-linear encoding
    else if(index == 6)
    {
        gen_8bit_bijection(6, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }

    // degree-7 8-bit non-linear encoding
    else if(index == 7)
    {
        gen_8bit_bijection(7, non8linear);
        for(x = 0; x < 256; x++)
        {
            temp = SBox[x ^ real_key];
            map[x] = non8linear[temp];
        }
    }
}

int DCA(uint8_t map[256])
{
    uint8_t kk, state;
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    double keystate[256][8][9] = {0.0};
    double keycurve[256][9] = {0.0};
    for(int j = 0; j < 256; j++)//key
    {
        kk = j;
        for(int r = 0; r < 8; r++) // bit
        {
            double split0[8] = {0.0};
            double split1[8] = {0.0};
            int count0 = 0;
            int count1 = 0;
            for(int i = 0; i < 256; i++) // plaintext
            {
                state = SBox[i ^ kk];
                if(state & identM8[r])
                {
                    for(int g = 0; g < 8; g++)
                    {
                        split1[g] += trace[i][g];
                    }
                    count1++;
                }
                else
                {
                    for(int g = 0; g < 8; g++)
                    {
                        split0[g] += trace[i][g];
                    }
                    count0++;
                }
            }
            for(int y = 0; y < 8; y++)
            {
                split0[y] = split0[y] / count0;
                split1[y] = split1[y] / count1;
            }
            for(int y = 0; y < 8; y++)
            {
                if(split0[y] >= split1[y]) keystate[kk][r][y] = split0[y] - split1[y];
                else keystate[kk][r][y] = split1[y] - split0[y];
            }
        }
        int maxord = 0;
        double maxvalue = 0.0;
        for(int i = 0; i < 8; i++)
        {
            double peak = 0.0;
            for(int j = 0; j < 8; j++)
            {
                if (keystate[kk][i][j] > peak) peak = keystate[kk][i][j]; // max in each curve
            }
            keystate[kk][i][8] = peak;
        }
        for(int i = 0; i < 8; i++)
        {
            if(keystate[kk][i][8] > maxvalue) 
            {
                maxord = i; // the corresponding bit of the peak
                maxvalue = keystate[kk][i][8];
            }
        }
        for(int i = 0; i < 9; i++) // the peak vaule as the peak of the key
        {
            keycurve[kk][i] = keystate[kk][maxord][i];
        }
    }
    double key_guess_value = 0.0;
    int key_guess = 0;
    for(int k = 0; k < 256; k++)
    {
        if(keycurve[k][8] > key_guess_value)
        {
            key_guess_value = keycurve[k][8];
            key_guess = k;
        }
    }
    if(key_guess == real_key) return 1;
    return 0;
}

int IDCA(uint8_t map[256])
{
    uint8_t  kk, state;
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    double keycurve[256][9] = {0.0};
    for(int kk = 0; kk < 256; kk++) //key
    {
        double lecurve[256][9] = {0.0};
        for(int le = 0; le < 256; le++) // linear encoding
        {
            double split0[8] = {0.0};
            double split1[8] = {0.0};
            int count0 = 0;
            int count1 = 0;
            for(int i = 0; i < 256; i++) // plaintext
            {
                state = xor[le & SBox[i ^ kk]];
                if(state)
                {
                    for(int g = 0; g < 8; g++)
                    {
                        split1[g] += trace[i][g];
                    }
                    count1++;
                }
                else
                {
                    for(int g = 0; g < 8; g++)
                    {
                        split0[g] += trace[i][g];
                    }
                    count0++;
                }
            }
            for(int y = 0; y < 8; y++)
            {
                split0[y] = split0[y] / count0;
                split1[y] = split1[y] / count1;
            }
            for(int y = 0; y < 8; y++)
            {
                if(split0[y] >= split1[y]) lecurve[le][y] = split0[y] - split1[y];
                else lecurve[le][y] = split1[y] - split0[y];
            }
            double peak = 0.0;
            for(int j = 0; j < 8; j++)
            {
                if (lecurve[le][j] > peak) peak = lecurve[le][j]; // max in each curve
            }
            lecurve[le][8] = peak;
        }
        double maxlepeak = 0.0;
        uint8_t maxle = 0;
        for(int le = 0; le < 256; le++) // linear encoding
        {
            if(lecurve[le][8] > maxlepeak) 
            {
                maxle = le;
                maxlepeak = lecurve[le][8];
            }
        }
        if(maxlepeak > 0.30) 
        {
            for(int i = 0; i < 9; i++)
            {
                keycurve[kk][i] = lecurve[maxle][i];
            }
        }
        else if(maxlepeak >= 0.20 && maxlepeak <= 0.30) 
        {
            for(int le = 0; le < 256; le++) // look for a value 0.25
            {
                if(lecurve[le][8] == 0.25) 
                {
                    for(int i = 0; i < 9; i++)
                    {
                        keycurve[kk][i] = lecurve[le][i];
                    }
                    break;
                }
            }
        }
        else if(maxlepeak < 0.20) 
        {
            for(int le = 0; le < 256; le++) // look for a value 0.25
            {
                if(lecurve[le][8] == 0.0) 
                {
                    for(int i = 0; i < 9; i++)
                    {
                        keycurve[kk][i] = lecurve[le][i];
                    }
                    break;
                }
            }
        }
    }
    double maxkeypeak = 0.0;
    uint8_t maxkey = 0;
    for(int i = 0; i < 256; i++) // ranking the candidates
    {
        if(keycurve[i][8] > maxkeypeak) 
        {
            maxkey = i;
            maxkeypeak = keycurve[i][8];
        }
    }
    if(maxkeypeak > 0.30) 
    {
        if(maxkey == real_key) return 1;
    }
    else if(maxkeypeak >= 0.20 && maxkeypeak <= 0.30) 
    {
        for(int i = 0; i < 256; i++) // look for a value 0.25
        {
            if(keycurve[i][8] == 0.25) 
            {
                maxkey = i;
                maxkeypeak = keycurve[i][8];
                if(maxkey == real_key) return 1;
                break;
            }
        }
    }
    else if(maxkeypeak < 0.20) 
    {
        for(int i = 0; i < 256; i++) // look for a value 0
        {
            if(keycurve[i][8] == 0.0) 
            {
                maxkey = i;
                maxkeypeak = keycurve[i][8];
                if(maxkey == real_key) return 1;
                break;
            }
        }
    }
    return 0;
}

int CPA(uint8_t map[256])
{
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    double score[256][8] = {0.0};
    double kmax[256] = {0.0};
    int f = 0, g = 0, k, j, i, c;
    uint8_t key_candidate[8] = {0};
    double key_candidate_value[8] = {0.0};
    for(c = 0; c < 8; c++) // bits of SBox
    {
        for(k = 0; k < 256; k++) // key
        {
            for(j = 0; j < 8; j++) // samples of trace
            {
                int Nf0 = 0, Nf1 = 0, Ng0 = 0, Ng1 = 0, N00 = 0, N01 = 0, N10 = 0, N11 = 0;
                for(i = 0; i < 256; i++) // plaintext
                {
                    f = trace[i][j];
                    if(f) Nf1++;
                    else Nf0++;

                    g = (SBox[i ^ k] >> (7 - c)) & 1; // a bit of SBox
                    if(g) Ng1++;
                    else Ng0++;
                    
                    if(f == 1 && g == 1) N11++;
                    else if(f == 0 & g == 0) N00++;
                    else if(f == 1 & g == 0) N10++;
                    else N01++;
                }
                score[k][j] = abs((N11 * N00 - N10 * N01)) * 1.0 / (sqrt(Nf1) * sqrt(Nf0) * sqrt(Ng1) * sqrt(Ng0));
            }
        }
        for(k = 0; k < 256; k++)
        {
            double max = 0.0;
            for(j = 0; j < 8; j++)
            {
                if(score[k][j] > max) max = score[k][j];
            }
            kmax[k] = max;
        }
        double key_guess_value = 0.0;
        int key_guess = 0;
        for(k = 0; k < 256; k++)
        {
            if(kmax[k] > key_guess_value)
            {
                key_guess_value = kmax[k];
                key_guess = k;
            }
        }
        key_candidate[c] = key_guess;
        key_candidate_value[c] = key_guess_value;
    }
    uint8_t key_max = 0;
    double key_max_cor = 0.0;
    for(c = 0; c < 8; c++)
    {
        if(key_candidate_value[c] > key_max_cor)
        {
            key_max = key_candidate[c];
            key_max_cor = key_candidate_value[c];
        }
    }
    if(key_max == real_key) return 1;
    else return 0;
}

int CA(uint8_t map[256])
{
    uint8_t temp;
    uint8_t trace[32640][8] = {0};
    int num = 0;
    for(int i = 0; i < 255; i++)
    {
        for(int j = i + 1; j < 256; j++)
        {
            temp = map[i] ^ map[j] ^ 0xff;
            for(int r = 0; r < 8; r++)
            {
                if(temp & identM8[r]) trace[num][r] = 1;
                else trace[num][r] = 0;
            }
            num++;
        }
    }
    ////
    double score[256][8] = {0.0};
    double kmax[256] = {0.0};
    int f = 0, g = 0, k, j, x1, x2, c;
    uint8_t key_candidate[8] = {0};
    double key_candidate_value[8] = {0.0};
    for(c = 0; c < 8; c++) // bits of SBox
    {
        for(k = 0; k < 256; k++) // key
        {
            for(j = 0; j < 8; j++) // column
            {
                int Nf0 = 0, Nf1 = 0, Ng0 = 0, Ng1 = 0, N00 = 0, N01 = 0, N10 = 0, N11 = 0;
                num = 0;
                for(x1 = 0; x1 < 255; x1++) // plaintext
                {
                    for(x2 = x1 + 1; x2 < 256; x2++) // plaintext
                    {
                        f = trace[num++][j];
                        if(f) Nf1++;
                        else Nf0++;

                        g = ((SBox[x1 ^ k] ^ SBox[x2 ^ k] ^ 0xff) >> (7 - c)) & 1; // a bit of SBox
                        if(g) Ng1++;
                        else Ng0++;
                        
                        if(f == 1 && g == 1) N11++;
                        else if(f == 0 & g == 0) N00++;
                        else if(f == 1 & g == 0) N10++;
                        else N01++;
                    }
                }
                score[k][j] = abs((N11 * N00 - N10 * N01)) * 1.0 / (sqrt(Nf1) * sqrt(Nf0) * sqrt(Ng1) * sqrt(Ng0));
            }
        }
        for(k = 0; k < 256; k++)
        {
            double max = 0.0;
            for(j = 0; j < 8; j++)
            {
                if(score[k][j] > max) max = score[k][j];
            }
            kmax[k] = max;
        }
        double key_guess_value = 0.0;
        int key_guess = 0;
        for(k = 0; k < 256; k++)
        {
            if(kmax[k] > key_guess_value)
            {
                key_guess_value = kmax[k];
                key_guess = k;
            }
        }
        key_candidate[c] = key_guess;
        key_candidate_value[c] = key_guess_value;
    }
    uint8_t key_max = 0;
    double key_max_cor = 0.0;
    for(c = 0; c < 8; c++)
    {
        if(key_candidate_value[c] > key_max_cor)
        {
            key_max = key_candidate[c];
            key_max_cor = key_candidate_value[c];
        }
    }
    if(key_max == real_key) return 1;
    else return 0;
}

int MIA(uint8_t map[256])
{
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    double score[256][8] = {0.0};
    double kmax[256] = {0.0};
    int f = 0, g = 0, k, j, i, c;
    uint8_t key_candidate[8] = {0};
    double key_candidate_value[8] = {0.0};
    for(c = 0; c < 8; c++) // bits of SBox
    {
        for(k = 0; k < 256; k++) // key
        {
            for(j = 0; j < 8; j++) // column
            {
                int Nf0 = 0, Nf1 = 0, Ng0 = 0, Ng1 = 0, N00 = 0, N01 = 0, N10 = 0, N11 = 0;
                double Pf0 = 0.0, Pf1 = 0.0, Pg0 = 0.0, Pg1 = 0.0, P00 = 0.0, P01 = 0.0, P10 = 0.0, P11 = 0.0, I00 = 0.0, I01 = 0.0, I10 = 0.0, I11 = 0.0;
                for(i = 0; i < 256; i++) // plaintext
                {
                    f = trace[i][j];
                    if(f) Nf1++;
                    else Nf0++;

                    g = (SBox[i ^ k] >> (7 - c)) & 1; // a bit of SBox
                    if(g) Ng1++;
                    else Ng0++;
                    
                    if(f == 1 && g == 1) N11++;
                    else if(f == 0 & g == 0) N00++;
                    else if(f == 1 & g == 0) N10++;
                    else N01++;
                }
                Pf0 = Nf0 * 1.0 / 256;
                Pf1 = Nf1 * 1.0 / 256;
                Pg0 = Ng0 * 1.0 / 256;
                Pg1 = Ng1 * 1.0 / 256;

                P00 = N00 * 1.0 / 256;
                P01 = N01 * 1.0 / 256;
                P10 = N10 * 1.0 / 256;
                P11 = N11 * 1.0 / 256;

                if(P00 == 0.0) I00 = 0.0;
                else I00 = P00 * log10(P00 / (Pf0 * Pg0)) / log10(2.0);
                
                if(P01 == 0.0) I01 = 0.0;
                else I01 = P01 * log10(P01 / (Pf0 * Pg1)) / log10(2.0);
                
                if(P10 == 0.0) I10 = 0.0;
                else I10 = P10 * log10(P10 / (Pf1 * Pg0)) / log10(2.0);
                
                if(P11 == 0.0) I11 = 0.0;
                else I11 = P11 * log10(P11 / (Pf1 * Pg1)) / log10(2.0);
                
                score[k][j] = I00 + I01 + I10 + I11;
            }
        }
        for(k = 0; k < 256; k++)
        {
            double max = 0.0;
            for(j = 0; j < 8; j++)
            {
                if(score[k][j] > max) max = score[k][j];
            }
            kmax[k] = max;
        }
        double key_guess_value = 0.0;
        int key_guess = 0;
        for(k = 0; k < 256; k++)
        {
            if(kmax[k] > key_guess_value)
            {
                key_guess_value = kmax[k];
                key_guess = k;
            }
        }
        key_candidate[c] = key_guess;
        key_candidate_value[c] = key_guess_value;
    }
    uint8_t key_max = 0;
    double key_max_cor = 0.0;
    for(c = 0; c < 8; c++)
    {
        if(key_candidate_value[c] > key_max_cor)
        {
            key_max = key_candidate[c];
            key_max_cor = key_candidate_value[c];
        }
    }
    if(key_max == real_key) return 1;
    else return 0;
}

int SA(uint8_t map[256])
{
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    int kmax[256] = {0};
    int k, j, x, w, WT;
    for(k = 0; k < 256; k++) // key
    {
        for(w = 0; w < 256; w++) // w <- Walsh transforms
        {
            for(j = 0; j < 8; j++) // column
            {
                WT = 0;
                for(x = 0; x < 256; x++) // plaintext
                {
                    if(trace[inv_SBox[x] ^ k][j] == xor[x & w]) WT++;
                    else WT--;
                }
                kmax[k] += abs(WT);
            }
        }
    }
    int key_guess_value = kmax[0];
    int key_guess = 0;
    for(k = 0; k < 256; k++)
    {
        if(kmax[k] < key_guess_value) // minimum
        {
            key_guess_value = kmax[k];
            key_guess = k;
        }
    }
    if(key_guess == real_key) return 1;
    return 0;
}

int MSA(uint8_t map[256])
{
    int trace[256][8] = {0};
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i] & identM8[j]) trace[i][j] = 1;
            else trace[i][j] = 0;
        }
    }
    ////
    int kmax[256] = {0};
    int k, j, x, w, WT;
    for(k = 0; k < 256; k++) // key
    {
        for(w = 0; w < 8; w++) // a particular bit of x
        {
            for(j = 0; j < 8; j++) // column
            {
                WT = 0;
                for(x = 0; x < 256; x++) // plaintext
                {
                    if(trace[x][j] == xor[SBox[x ^ k] & identM8[w]]) WT++;
                    else WT--;
                }
                kmax[k] += abs(WT);
            }
        }
    }
    int key_guess_value = kmax[0];
    int key_guess = 0;
    for(k = 0; k < 256; k++)
    {
        if(kmax[k] < key_guess_value) // minimum
        {
            key_guess_value = kmax[k];
            key_guess = k;
        }
    }
    if(key_guess == real_key) return 1;
    else return 0;
}

int ISA(uint8_t map[256])
{
    int kmax[256] = {0};
    int k, u, x, v, WT;
    for(k = 0; k < 256; k++) // key
    {
        for(u = 0; u < 256; u++) // u <- Walsh transforms on x
        {
            for(v = 0; v < 256; v++) // v <- Walsh transforms on traces
            {
                WT = 0;
                for(x = 0; x < 256; x++) // plaintext
                {
                    if(xor[map[inv_SBox[x] ^ k] & v] == xor[x & u]) WT++;
                    else WT--;
                }
                if(WT == 0) kmax[k]++;
            }
        }
    }
    int key_guess_value = kmax[0];
    int key_guess = 0;
    for(k = 0; k < 256; k++)
    {
        if(kmax[k] > key_guess_value) // maximum
        {
            key_guess_value = kmax[k];
            key_guess = k;
        }
    }
    if(key_guess == real_key) return 1;
    else return 0;
}

int ADCA(uint8_t map[256], int attack_degree) // algebraic degree computation analysis
{
    uint8_t temp;
    int bit, x, cb;
    static const int n = 8;
    int column;
    uint8_t Htrace[256][247];
    uint8_t vector[256];
    uint8_t x_bit[256][8];
    int kc[256] = {0};
    uint8_t trail[8605][3];// Gaussian trail
    int degree = attack_degree; // adjustable attack degree
    // for(int degree = 1; degree <= attack_degree; degree++) // Also can sum the results of different degrees
    {
        memset(Htrace, 0, sizeof(Htrace));
        for(x = 0; x < 256; x++)
        {
            for(bit = 0; bit < 8; bit++)
            {
                if(x & identM8[bit]) x_bit[x][bit] = 1;
                else x_bit[x][bit] = 0;
            }
            Htrace[x][0] = 1;
            column = 1;
            for(cb = 1; cb <= degree; cb++)// ANF funtion
            {
                for(int i = 0; i < (1 << n); i++)
                {
                    int num = 0, kk = i;
                    while(kk)
                    {
                        kk = kk & (kk - 1);
                        num++;
                    }
                    if(num == cb)
                    {
                        Htrace[x][column] = 1;
                        for(int j = 0; j < n; j++)
                        {
                            if(i & (1 << j)) Htrace[x][column] &= x_bit[x][j];
                        }
                        column++;
                    }
                }
            }
        }
        int Gauss_time = 0;
        //  Gaussian Elimination
        for(int i = 0; i < column; i++)
        {
            if(Htrace[i][i])
            {
                for(int j = i + 1; j < 256; j++)
                {
                    if(Htrace[j][i])
                    { 
                        for(int r = 0; r < column; r++)
                        {
                            Htrace[j][r] ^= Htrace[i][r];
                        }
                        trail[Gauss_time][0] = 1; //addition
                        trail[Gauss_time][1] = j;
                        trail[Gauss_time][2] = i;
                        Gauss_time++;
                    }
                }
            }
            else
            {
                int flag = 0;
                for(int j = i + 1; j < 256; j++)
                {
                    if(Htrace[j][i])
                    {
                        for(int r = 0; r < column; r++)
                        {
                            temp = Htrace[i][r];
                            Htrace[i][r] = Htrace[j][r];
                            Htrace[j][r] = temp;
                        }
                        trail[Gauss_time][0] = 0; //swap
                        trail[Gauss_time][1] = j;
                        trail[Gauss_time][2] = i;
                        Gauss_time++;

                        flag = 1;
                        break;
                    }
                }
                if(flag)
                {
                    for(int j = i + 1; j < 256; j++)
                    {
                        if(Htrace[j][i])
                        { 
                            for(int r = 0; r < column; r++)
                            {
                                Htrace[j][r] ^= Htrace[i][r];
                            }
                            trail[Gauss_time][0] = 1; //addition
                            trail[Gauss_time][1] = j;
                            trail[Gauss_time][2] = i;
                            Gauss_time++;
                        }
                    }
                }
            }
        }
        // printf("Gauss time: %d\n", Gauss_time);
        // return 0;

        // the rank of A
        int rA = 256;
        for(int i = 255; i >= 0; i--)
        {
            int allzero = 1;
            for(int j = 0; j < column; j++)
            {
                if(Htrace[i][j]) allzero = 0;
            }
            if(allzero) rA--;
            else break;
        }

        for(int k = 0; k < 256; k++) // key
        {
            for(bit = 0; bit < 8; bit++)
            {
                for(x = 0; x < 256; x++)
                {
                    if(map[inv_SBox[x] ^ k] & identM8[bit]) vector[x] = 1;
                    else vector[x] = 0;
                }
                //  Gaussian Elimination
                for(int i = 0; i < Gauss_time; i++)
                {
                    if(trail[i][0]) // addition
                    {
                        vector[trail[i][1]] ^= vector[trail[i][2]];
                    }
                    else // swap
                    {
                        temp = vector[trail[i][2]];
                        vector[trail[i][2]] = vector[trail[i][1]];
                        vector[trail[i][1]] = temp;
                    }
                }
                
                // Gauss Over
                int rAb = 256;
                for(int i = 255; i >= 0; i--)
                {
                    int allzero = 1;
                    if(vector[i]) allzero = 0;
                    if(allzero) rAb--;
                    else break;
                }
                if(rA >= rAb) // has a solusion
                {
                    kc[k]++;
                }
            }
        }
    }
    int key_max = 0, key_index = 0;
    for(int i = 0; i < 256; i++)
    {
        if(kc[i] > key_max)
        {
            key_max = kc[i];
            key_index = i;
        }
    }
    if(key_index == real_key) return 1;
    return 0;
}