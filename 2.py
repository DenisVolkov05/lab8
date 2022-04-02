import math
def y_toch(x):
    return -2*(math.cos(x)**2) + math.cos(x)
def f(x, y):
    return -y*math.tan(x) + math.sin(2*x)
y = [0]*11
dy = [0]*11
x = [0]*11
eps = [0]*11
k = [[0]*5]*11
h = 0.1
y[0] = -1
for i in range (11):
    x[i] = i*h
for i in range (10):
    k[i][0] = h*f(x[i],y[i])
    k[i][1] = h*f(x[i] + h/2,y[i] + k[i][0]/2)
    k[i][2] = h*f(x[i] + h/2,y[i] + k[i][1]/2)
    k[i][3] = h*f(x[i] + h,y[i] + k[i][2])
    dy[i] = (k[i][0] + 2*k[i][1] + 2*k[i][2] + k[i][3])/6
    y[i+1] = y[i]+dy[i]
for i in range (11):
    eps[i] = abs(y[i] - y_toch(x[i]))
    print ("x",i,": ",x[i],"   y",i,": ",y[i],"   Погрешность eps:",eps[i],sep='')     
    
