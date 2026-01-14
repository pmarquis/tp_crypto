void Cipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]);
void InvCipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]);
void SubBytes(u8 in_state[4][4], u8 out_state[4][4]);