import matplotlib.pyplot as plt


filename = "1411.in"
f = open(filename, "r")

n = int(f.readline())

point = []

for i in f:
	x, y = [float(x) for x in i.split()]
	point.append([x, y])

match = []
f2 = open("1411.out")

cnt = 0
for i in f2:
	x = int(i) - 1
	print("%d connect to %d" % (cnt + 1, x + 1))
	x1, y1 = point[cnt]
	x2, y2 = point[x + n]
	
	plt.plot([x1, x2], [y1, y2], marker = 'o')

	cnt += 1

# for i in range(n):
# 	(x, y) = point[i]
# 	plt.plot(x, y, 'ro')

# for i in range(n):
# 	(x, y) = point[i + n]
# 	plt.plot(x, y, 'bo')
	
plt.show()