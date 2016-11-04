#if __BYTE_ORDER == __BIG_ENDIAN
      unsigned sign : 1;
      unsigned exp : _FP_EXPBITS_Q;
      unsigned long frac3 : _FP_FRACBITS_Q - (_FP_IMPLBIT_Q != 0)-(_FP_W_TYPE_SIZE * 3);
      unsigned long frac2 : _FP_W_TYPE_SIZE;
      unsigned long frac1 : _FP_W_TYPE_SIZE;
      unsigned long frac0 : _FP_W_TYPE_SIZE;
#else
      unsigned long frac0 : _FP_W_TYPE_SIZE;
      unsigned long frac1 : _FP_W_TYPE_SIZE;
      unsigned long frac2 : _FP_W_TYPE_SIZE;
      unsigned long frac3 : _FP_FRACBITS_Q - (_FP_IMPLBIT_Q != 0)-(_FP_W_TYPE_SIZE * 3);
      unsigned exp : _FP_EXPBITS_Q;
      unsigned sign : 1;
#endif 
/* not bigendian */
   } bits __attribute__((packed));
};
#define FP_DECL_Q(X)		_FP_DECL(4,X)
#define FP_UNPACK_RAW_Q(X,val)	_FP_UNPACK_RAW_4(Q,X,val) /* hi,
this is a
  weird one*/
#define FP_UNPACK_RAW_QP(X,val)	_FP_UNPACK_RAW_4_P(Q,X,val)
#define FP_PACK_RAW_Q(val,X)	_FP_PACK_RAW_4(Q,val,X) // inline
#define FP_PACK_RAW_QP(val,X)		\
  do {					\
    if (!FP_INHIBIT_RESULTS)		\
      _FP_PACK_RAW_4_P(Q,val,X);	\
} while (0)
#define FP_UNPACK_Q(X,val)		\
  do {					\
    _FP_UNPACK_RAW_4(Q,X,val);		\
    _FP_UNPACK_CANONICAL(Q,4,X);	\
} while (0)
#define FP_UNPACK_QP(X,val)		\ // another inline
  do {					\
    _FP_UNPACK_RAW_4_P(Q,X,val);	\
    _FP_UNPACK_CANONICAL(Q,4,X);	\
} while (0)
/* hello
 *   hai
 *      woot indent!
 *
 * ok then
 */
#define FP_PACK_Q(val,X)		\
  do {					\
    _FP_PACK_CANONICAL(Q,4,X);		\
    _FP_PACK_RAW_4(Q,val,X);		\
} while (0)
#define FP_PACK_QP(val,X)		\
  do {					\
    _FP_PACK_CANONICAL(Q,4,X);		\
    if (!FP_INHIBIT_RESULTS)		\
      _FP_PACK_RAW_4_P(Q,val,X);	\
} while (0)
