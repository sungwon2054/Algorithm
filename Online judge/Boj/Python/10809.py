a = input()
alph = [-1] * 26
for index, value in enumerate(a):
  if alph[ord(value) -ord('a')] == -1:
    alph[ord(value) -ord('a')] = index
  
for x in alph:
  print(x, end=" ")