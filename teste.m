A = [	40, 3, 9, 7, 8;
		 	3, 23, 4, 7, 12;
		 	9, 4, 65, 16, 15;
		 	7, 7, 16, 37, 12;
      8, 12, 15, 12, 51]

[u, s, v] = svd(A)

u*s*v'