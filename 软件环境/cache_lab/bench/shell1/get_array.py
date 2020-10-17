import numpy as np

n = 4

while 1:
	a = np.random.randint(n*n,size=(n, n))
	# a = np.random.rand(n, n)
	det = np.linalg.det(a)
	if det!=0:
		break

b = np.linalg.inv(a) * det
b = b.astype(int)

c = np.matmul(a, b)

def print_numpy_array(a):
	n = a.shape[0]
	print('{')
	for i in range(n):
		for j in range(n):
			if i==n-1 and j==n-1:
				print(a[i][j], end=' ')
			else:
				print(a[i][j], end=', ')
		print('\\')
	print('}')

print_numpy_array(a)
print_numpy_array(b)
print_numpy_array(c)