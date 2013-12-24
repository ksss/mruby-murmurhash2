#include <mruby.h>
#include <mruby/string.h>

#define MURMURHASH_MAGIC 0x5bd1e995

static inline uint32_t
murmur2(uint32_t h, uint32_t k, const uint8_t r)
{
  const uint32_t m = MURMURHASH_MAGIC;
  k *= m;
  k ^= k >> r;
  k *= m;
  
  h *= m;
  h ^= k;
  return h;
}

static uint32_t
murmur_hash_process2(char *str, int length)
{
  const uint32_t m = MURMURHASH_MAGIC;
  const uint8_t r = 24;
  uint32_t h, k;
  const char* p;

  p = str;
  h = length * m;

  while (4 <= length) {
    k = *(uint32_t*)p;
    h = murmur2(h, k, r);
    p += 4;
    length -= 4;
  }

  switch (length) {
  case 3: h ^= p[2] << 16;
  case 2: h ^= p[1] << 8;
  case 1: h ^= p[0];
    h *= m;
  }

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}

static mrb_value
mrb_murmurhash2_digest(mrb_state *mrb, mrb_value self)
{
  mrb_value str;
  uint32_t value;
  uint8_t digest[4];

  mrb_get_args(mrb, "S", &str);
  value = murmur_hash_process2(RSTRING_PTR(str), RSTRING_LEN(str));

  digest[0] = value >> 24;
  digest[1] = value >> 16;
  digest[2] = value >> 8;
  digest[3] = value;

  return mrb_str_new(mrb, (char*) digest, 4);
}

void
mrb_mruby_murmurhash2_gem_init(mrb_state *mrb)
{
  struct RClass *mMurmurhash1 = mrb_define_module(mrb, "Murmurhash2");
  mrb_define_class_method(mrb, mMurmurhash1, "digest", mrb_murmurhash2_digest, ARGS_REQ(1));
}

void
mrb_mruby_murmurhash2_gem_final(mrb_state *mrb)
{
}
