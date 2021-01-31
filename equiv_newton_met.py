import math
aprox_1=1e-8
aprox_2=1e-16
def solve(func,dev_func,top,bot,approach=aprox_1):
    if func(top)==0:
        print("Solve code 1") 
        return [top,top]
    if func(bot)==0:
        print("Sovle code 2")
        return [bot,bot]
    res_1=res_2=0
    x=bot
    while abs(func(x))>approach:
        x-=func(x)/dev_func(x)
    res_1=x
    x=top
    while abs(func(x))>approach:
        x-=func(x)/dev_func(x)
    res_2=x
    return [res_1,res_2]
def f(d):
    return d*math.exp(d)-1
def dev_f(d):
    return (d+1)*math.exp(d)
print(solve(f,dev_f,1,0,1e-24))