# mruby-murmurhash2

murmurhash2 digest.

```ruby
puts Murmurhash2::digest('mruby') #=> "\xda\x2a\x7f\xca"
```

## Installation

Write in build_config.rb

```ruby
MRuby::Build.new do |conf|
  conf.gem :github => 'ksss/mruby-murmurhash2', :branch => 'master'
end
```

and exec.

```
rake clean
rake test
rake
mruby -e 'puts Murmurhash2::digest("mruby")'
```
