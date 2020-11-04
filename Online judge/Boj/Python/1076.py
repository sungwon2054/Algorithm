dic = { 'black':0, 'brown':1, 'red':2, 'orange':3, 'yellow':4, 'green':5,
        'blue':6, 'violet':7, 'grey':8, 'white':9}
color = []
for _ in range(3):
  a = input()
  color.append(a)
print((dic[color[0]] * 10 + dic[color[1]]) * (10 ** dic[color[2]]))