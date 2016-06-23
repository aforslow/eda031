#ifndef CODE_H_
#define CODE_H_

static unsigned char encode(unsigned char c);
return c^key;

/* For any character c, decode(encode(c)) == c */
static unsigned char decode(unsigned char c);
return c^key;

static const unsigned char key = 20;

#endif
