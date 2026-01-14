#include "integration.h"
#include <stdio.h>

void SubBytes(u8 in_state[4][4], u8 out_state[4][4])
{
    u8 r, c;
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
            u8 a = in_state[r][c];
            u8 x = (u8)(a >> 4);
            u8 y = (u8)(a & 0x0F);
            out_state[r][c] = s_box[x][y];
        }
    }
}

void Cipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]) {

}
void KeyExpansion(u8 key[4*Nk], u32 sub_key[Nb*(Nr+1)]) {
	(void)key;
	(void)sub_key;
	// TODO: implémenter KeyExpansion
}
void InvCipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]) {

}