/*
 * utils.c
 */
#include "tl_common.h"
#include "drivers.h"
#include "common/utility.h"


inline void bbcopy(register unsigned char * src, register unsigned char * dest, unsigned int len) {
	if (dest < src)
		while (len--)
			*dest++ = *src++;
	else {
		unsigned char *lasts = src + (len - 1);
		unsigned char *lastd = dest + (len - 1);
		while (len--)
			*(unsigned char *) lastd-- = *(char *) lasts--;
	}
}

inline void bcopy(register unsigned char * src, register unsigned char * dest, unsigned int len) {
	bbcopy(src, dest, len);
}

_attribute_ram_code_
void * memset(void * dest, int val, unsigned int len) {
	register unsigned char *ptr = (unsigned char*) dest;
	while (len-- > 0)
		*ptr++ = (unsigned char)val;
	return dest;
}

_attribute_ram_code_
void * memcpy(void * out, const void * in, unsigned int length) {
	bcopy((unsigned char *) in, (unsigned char *) out, (int) length);
	return out;
}

_attribute_ram_code_
int memcmp(const void * m1, const void *m2, unsigned int len) {
	unsigned char *st1 = (unsigned char *) m1;
	unsigned char *st2 = (unsigned char *) m2;

	while(len--){
		if(*st1 != *st2){
			return (*st1 - *st2);
		}
		st1++;
		st2++;
	}
	return 0;
}

/****************************************************************************
 * @fn          addrExtCmp
 *
 * @brief       Compare two extended addresses.
 *
 * input parameters
 *
 * @param       pAddr1        - Pointer to first address.
 * @param       pAddr2        - Pointer to second address.
 *
 * output parameters
 *
 * @return      TRUE if addresses are equal, FALSE otherwise
 */
u8 addrExtCmp(const u8 * pAddr1, const u8 * pAddr2)
{
  u8 i;

  for (i = 8; i != 0; i--)
  {
    if (*pAddr1++ != *pAddr2++)
    {
      return FALSE;
    }
  }
  return TRUE;
}


// general swap/endianess utils

void swapN(unsigned char *p, int n)
{
	int i, c;
	for (i=0; i<n/2; i++)
	{
		c = p[i];
		p[i] = p[n - 1 - i];
		p[n - 1 - i] = c;
	}
}

void swapX(const u8 *src, u8 *dst, int len)
{
    int i;
    for (i = 0; i < len; i++)
        dst[len - 1 - i] = src[i];
}

void swap24(u8 dst[3], const u8 src[3])
{
    swapX(src, dst, 3);
}

void swap32(u8 dst[4], const u8 src[4])
{
    swapX(src, dst, 4);
}

void swap48(u8 dst[7], const u8 src[7])
{
    swapX(src, dst, 6);
}

void swap56(u8 dst[7], const u8 src[7])
{
    swapX(src, dst, 7);
}

void swap64(u8 dst[8], const u8 src[8])
{
    swapX(src, dst, 8);
}

void swap128(u8 dst[16], const u8 src[16])
{
    swapX(src, dst, 16);
}

void net_store_16(u8 *buffer, u16 pos, u16 value)
{
    buffer[pos++] = value >> 8;
    buffer[pos++] = value;
}


void flip_addr(u8 *dest, u8 *src){
    dest[0] = src[5];
    dest[1] = src[4];
    dest[2] = src[3];
    dest[3] = src[2];
    dest[4] = src[1];
    dest[5] = src[0];
}

void store_16(u8 *buffer, u16 pos, u16 value){
    buffer[pos++] = value;
    buffer[pos++] = value >> 8;
}



void my_fifo_init (my_fifo_t *f, int s, u8 n, u8 *p)
{
	f->size = s;
	f->num = n;
	f->wptr = 0;
	f->rptr = 0;
	f->p = p;
}
_attribute_ram_code_
u8* my_fifo_wptr (my_fifo_t *f)
{
	if (((f->wptr - f->rptr) & 255) < f->num)
	{
		return f->p + (f->wptr & (f->num-1)) * f->size;
	}
	return 0;
}
/*
void my_fifo_next (my_fifo_t *f)
{
	f->wptr++;
}
*/
_attribute_ram_code_
int my_fifo_push (my_fifo_t *f, u8 *p, int n)
{
	if (((f->wptr - f->rptr) & 255) >= f->num)
	{
		return -1;
	}

	if (n >= f->size)
	{
		return -1;
	}
	u8 *pd = f->p + (f->wptr++ & (f->num-1)) * f->size;
	*pd++ = n & 0xff;
	*pd++ = (n >> 8) & 0xff;
	memcpy (pd, p, n);
	return 0;
}
/*
void my_fifo_pop (my_fifo_t *f)
{
	f->rptr++;
}
*/
_attribute_ram_code_
u8 * my_fifo_get (my_fifo_t *f)
{
	if (f->rptr != f->wptr)
	{
		u8 *p = f->p + (f->rptr & (f->num-1)) * f->size;
		return p;
	}
	return 0;
}


/**
 * fls - find last (most-significant) bit set
 * @x: the word to search
 *
 * This is defined the same way as ffs.
 * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
 */
//https://elixir.bootlin.com/linux/v5.7-rc4/source/include/asm-generic/bitops/fls.h#L13
static inline u32 fls(u32 x)
{
	u32 r = 32;

	if(!x){
		return 0;
	}
	if (!(x & 0xffff0000)) {
		x = x << 16;
		r = r-16;
	}
	if (!(x & 0xff000000)) {
		x <<= 8;
		r -= 8;
	}
	if (!(x & 0xf0000000)) {
		x <<= 4;
		r -= 4;
	}
	if (!(x & 0xc0000000)) {
		x <<= 2;
		r -= 2;
	}
	if (!(x & 0x80000000)) {
		x <<= 1;
		r -= 1;
	}
	return r;
}

//https://elixir.bootlin.com/linux/v5.7-rc4/source/lib/math/div64.c#L29
_attribute_ram_code_
u32 __div64_32(u64 *n, u32 base)
{
	u64 rem = *n;
	u64 b = base;
	u64 res, d = 1;
	u32 high = rem >> 32;

	/* Reduce the thing a bit first */
	res = 0;
	if (high >= base) {
		high /= base;
		res = (u64) high << 32;
		rem -= (u64) mul64_32x32(high, base) << 32;
	}

	while ((s64)b > 0 && b < rem) {
		b = b+b;
		d = d+d;
	}

	do {
		if (rem >= b) {
			rem -= b;
			res += d;
		}
		b >>= 1;
		d >>= 1;
	} while (d);

	*n = res;
	return rem;
}
//test demo: 0x50E01557,9A595A8C = 0x00000000,0000000A  *  0x08166888,C2A2890E
//           0x50E0154F,9A595A8C
static inline u64 mul_u64_u64_shr(u64 a, u64 b, u32 shift)
{
	union {
		u64 ll;
		struct {
#ifdef __BIG_ENDIAN
			u32 high, low;
#else //Telink MCU uses little endian
			u32 low, high;
#endif
		} l;
	} rl, rm, rn, rh, a0, b0;
	u64 c;

	a0.ll = a; //0x00000000 0000000A
	b0.ll = b; //0x08166888 C2A2890E

	rl.ll = mul64_32x32(a0.l.low, b0.l.low);  //0x0000000A*0xC2A2890E => (0x00000007 << 32) | 0x9a595a8c
	rm.ll = mul64_32x32(a0.l.low, b0.l.high); //0x0000000A*0x08166888 => (0x00000000 << 32) | 0x50e01550

	rn.ll = mul64_32x32(a0.l.high, b0.l.low); //0x00000000*0xC2A2890E => (0x00000000 << 32) | 0x00000000
	rh.ll = mul64_32x32(a0.l.high, b0.l.high);//0x00000000*0x08166888 => (0x00000000 << 32) | 0x00000000

	/*
	 * Each of these lines computes a 64-bit intermediate result into "c",
	 * starting at bits 32-95.  The low 32-bits go into the result of the
	 * multiplication, the high 32-bits are carried into the next step.
	 */
	rl.l.high = c = (u64)rl.l.high + rm.l.low + rn.l.low; //  (u64)0x00000007 + 0x50e01550 + 0x00000000

	//printf("c:0x%x\n", c);
	rh.l.low = c = (c >> 32) + rm.l.high + rn.l.high + rh.l.low;
	rh.l.high = (c >> 32) + rh.l.high;
	//printf("rl.l.low:0x%x : rl.l.high:0x%x\n", rl.l.high);
	/*
	 * The 128-bit result of the multiplication is in rl.ll and rh.ll,
	 * shift it right and throw away the high part of the result.
	 */
	if (shift == 0)
		return rl.ll;
	if (shift < 64)
		return (rl.ll >> shift) | (rh.ll << (64 - shift));
	return rh.ll >> (shift & 63);
}

/**
 * div64_u64 - unsigned 64bit divide with 64bit divisor
 * @dividend:	64bit dividend
 * @divisor:	64bit divisor
 *
 * This implementation is a modified version of the algorithm proposed
 * by the book 'Hacker's Delight'.  The original source and full proof
 * can be found here and is available for use without restriction.
 *
 * 'http://www.hackersdelight.org/hdcodetxt/divDouble.c.txt'
 */
//refer to:1. https://code.woboq.org/linux/linux/lib/div64.c.html //  2.https://elixir.bootlin.com/linux/latest/source/lib/math/div64.c#L102
//u64 AQUOT, AQUOTr, AREM, AREMr, AMULt;
_attribute_ram_code_
u64 __div64_64(u64* n, u64 divisor)
{
	u64 dividend = *n;
	u32 high = divisor >> 32;
	u64 quot;
	u64 rem;
//	printf("dividend:\n");
//	array_printf((u8*)&dividend, 8);
//	printf("divisor:\n");
//	array_printf((u8*)&divisor, 8);

	if (high == 0) {
		quot = div64_32(dividend, divisor);
		rem = div64_32mod(dividend, divisor);
//		printf("return ->\nquot:\n");
//		array_printf((u8*)&quot, 8);
//		printf("rem:\n");
//		array_printf((u8*)&rem, 8);
	} else {
		u32 n = fls(high);
//		printf("n:0x%x\n", n);
		quot = div64_32(dividend >> n, divisor >> n);
//		AQUOT = quot;
//		printf("quot:\n");
//		array_printf((u8*)&quot, 8);
		if (quot != 0){
			quot--;
//			printf("quot--:\n");
//			array_printf((u8*)&quot, 8);
		}
		u64 mul64_tmp = mul_u64_u64_shr(quot, divisor, 0);
//		printf("mul64_tmp:\n");
//		array_printf((u8*)&mul64_tmp, 8);

		rem = dividend - mul64_tmp;
//		AREM = rem;
//		printf("rem:\n");
//		array_printf((u8*)&rem, 8);

		if (rem >= divisor){
			quot++;
			rem -= divisor;
//			AREMr = rem;
//			printf("rem >= divisor\n");
//
//			printf("return ->\nquot++:\n");
//			array_printf((u8*)&quot, 8);
//			printf("rem:\n");
//			array_printf((u8*)&rem, 8);
		}
	}
//	AQUOTr = quot;

	*n = quot;
	return rem;
}
