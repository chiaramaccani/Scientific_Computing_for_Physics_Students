a  = 3
x = [1 for i in range(20)]
y = [4 for i in range(20)]
scalar_product = 0
for i in range(20):
    scalar_product += a*x[i]+y[i]
print(scalar_product)