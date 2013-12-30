assert 'digest mruby' do
  assert_equal(MurmurHash2::digest("mruby"), "\xda\x2a\x7f\xca")
end

assert 'digest murmur' do
  assert_equal(MurmurHash2::digest("murmur"), "\x21\x71\x77\xbc")
end


