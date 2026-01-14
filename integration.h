
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


#define Nk 4
#define Nb 4
#define Nr 10

// Déclarations externes
extern u32 Rcon[10];
extern u8 s_box[16][16];
extern u8 inv_s_box[16][16];

// Déclarations de fonctions
void Cipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]);
void InvCipher(u8 in[4*Nb], u8 out[4*Nb], u32 sub_key[Nb*(Nr+1)]);
void SubBytes(u8 in_state[4][4], u8 out_state[4][4]);