#define BITS_IN_UNIGNED_INT (int)(sizeof(int) * 8)
#define THREE_QUARTERS      (int)((BITS_IN_UNIGNED_INT * 3) / 4)
#define HASH_ONE_EIGHTH     (int)(BITS_IN_UNIGNED_INT / 8)
#define HASH_HIGH_BITS      (int)((unsigned int)(0xFFFFFFFF) << \
				(BITS_IN_UNIGNED_INT - HASH_ONE_EIGHTH))

#define PJW_HASH_FUNC(init_value) \
    unsigned char *pKey; \
    unsigned char *pEnd; \
    int hash; \
    int test; \
 \
    hash = init_value; \
    pEnd = (unsigned char *)key + key_len; \
    for (pKey = (unsigned char *)key; pKey != pEnd; pKey++) \
    { \
        hash = (hash << HASH_ONE_EIGHTH) + (*(pKey)); \
        if ((test = hash & HASH_HIGH_BITS) != 0) \
        { \
            hash = ((hash ^ (test >> THREE_QUARTERS)) & (~HASH_HIGH_BITS)); \
        } \
    } \
 \
    return hash; \


// P.J.Weinberger Hash Function, same as ELF Hash
int PJWHash(const void *key, const int key_len)
{
	PJW_HASH_FUNC(0)
}

