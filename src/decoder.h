#ifndef DECODER_H
#define DECODER_H

char string_buffer[1000];
char buffer1[16];
char buffer2[32];
char buffer3[20];
char buffer4[20];

char *str_cpy(char *, char *);
char *fmt_int_10(char *, u32, u8, u8);
char *gf_strcat(char *str1, char *str2);
void *memset(void *s, int c, u32 n);


void flush_string_buffer() {
	void mem_set(void *, u32, u32);
	mem_set(string_buffer, 0xFF, 1000);
	return;
}

char *str_cpy_len(char *dst, char *src, u32 size) {
	while (size > 0) {
		*dst++ = *src++;
		size --;
	}
	return dst;
}

u32 string_length(char *string) {
	char this_char = (char) 0;
	u32 size = 0;
	do {
		this_char = *string++;
		size++;
	} while (this_char != (char)0xFF);
	string[size] = 0xFF;
	return size;
}

char *int_to_str(char *dst, u32 *src) {
	return fmt_int_10(dst, *src, 1, 3);
}

#endif /* DECODER_H */
