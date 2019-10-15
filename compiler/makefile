fi=filename

.PHONY:

ci:
	gcc -E $(fi).c -o $(fi).i
cs: 
	gcc -S $(fi).i -o $(fi).s
co: 
	gcc -c $(fi).s -o $(fi).o
cout: 
	gcc $(fi).o -o $(fi).out

chi: cs co cout

crout: ci cs co cout

