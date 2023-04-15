h1 = {1=>3 , 2=>334}
h2 = h1.dup 
h2[3] = 333
h1[4] = 3

p h1 
p h2
p h1.object_id 
p h2.object_id

puts "Hogehoge"