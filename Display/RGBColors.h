#pragma once
// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x4D3F
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define fromRGB(r,g,b) = (((r & 0b11111000)<<8) + ((g & 0b11111100)<<3)+(b>>3))	//trasforma da RGB a 16-bit //(r << 11) + (g << 5) + b
#define PINK 0xFC18
#define ORANGE 0xFC00
#define GIALLO_ARANCIO 0xFE4A
#define VIOLA 0x8010
#define AZZURRO_CHIARO 0x07FF
#define AZZURRO_VERDE2  0x87F9
#define AZZURRO_VERDE  0x2FF4
#define GIALLO_VERDE 0xCFE0
#define BLU_VIOLA 0x73BF
#define ARANCIONE_SCURO 0xFB65