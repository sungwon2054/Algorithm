while True:
  try:
    lis = input()
    if len(lis) == 0: break
    capital, small, number, space = 0,0,0,0
    for x in lis:
      if 65 <= ord(x) and ord(x) <= 90:
        capital += 1
      elif 97 <= ord(x) and ord(x) <= 122:
        small += 1
      elif 48 <= ord(x) and ord(x) <= 57:
        number += 1
      elif ord(x) == 32:
        space += 1
    print(small,capital,number,space)
  except:
    break