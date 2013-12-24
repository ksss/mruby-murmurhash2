assert 'digest mruby' do
  assert_equal(Murmurhash2::digest("mruby"), "\xda\x2a\x7f\xca")
end

assert 'digest murmur' do
  assert_equal(Murmurhash2::digest("murmur"), "\x21\x71\x77\xbc")
end


