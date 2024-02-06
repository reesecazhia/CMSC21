n = 5

for i in range(0,2*n):
	print()
	for j in range(0,2*n):
		if  j==(n-1) or i == (n-1) or j==(2*n-1-i) or j==i:
			
			print("*", end="");
		else:
		
			print(" ", end="");
		