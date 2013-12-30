# mruby-murmurhash2

murmurhash2 digest.

```ruby
puts MurmurHash2::digest('mruby') #=> "\xda\x2a\x7f\xca"
```

## Installation

### use github repository

Write in build_config.rb

```ruby
MRuby::Build.new do |conf|
  conf.gem :github => 'ksss/mruby-murmurhash2', :branch => 'master'
end
```

### or use mgem

```
mgem add mruby-murmurhash2
```

### build

and exec.

```
rake clean
rake test
rake
mruby -e 'puts MurmurHash2::digest("mruby")'
```

## See also

[https://sites.google.com/site/murmurhash/](https://sites.google.com/site/murmurhash/)
