import sys
st = ""
while 1:
  try:
    s = input()
    st += s
  except:
    break 
st = list(map(int, st.split(',')))
print(sum(st))
