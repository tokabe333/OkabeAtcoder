a = [[1,2], [3,4]]
b = Marshal.load(Marshal.dump(a))

a[0][0] = 334
p a 
p b