MOD = 998244353

def mod_pow(base, exp, mod)
  res = 1
  while exp > 0
    res = res * base % mod if exp.odd?
    base = base * base % mod
    exp >>= 1
  end
  res
end

def mod_inv(x, mod)
  mod_pow(x, mod - 2, mod)
end

def calculate_series(n, m)
  a = mod_pow(10, n, MOD)
  
  if a == 1
    return (m + 1) % MOD
  end
  
  a_m_plus_1 = mod_pow(a, m + 1, MOD)
  numerator = (a_m_plus_1 - 1 + MOD) % MOD
  denominator_inv = mod_inv(a - 1, MOD)
  
  numerator * denominator_inv % MOD
end

n = gets.chomp.to_i 
nlen = n.to_s.length
m = calculate_series(nlen, n - 1)
# m = calculate_series(3, 1)
# puts m

puts (n * m) % MOD