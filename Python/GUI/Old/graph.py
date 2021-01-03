from collections import Counter
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.figure import Figure
from mpl_toolkits.mplot3d import Axes3D

def visualize(item,parsed_data,limit,nombre):
	plt.close('all')
	figure=plt.figure(nombre)
	counter=Counter(row[item] for row in parsed_data)
	limite=dict(counter.most_common(limit))
	labels=tuple(limite.keys())
	xlocations = np.arange(len(labels)) + 0.5
	width = 0.5
	a = figure.add_subplot(111)
	a.bar(xlocations,limite.values(),width=width)
	a.set_xticks(xlocations + width / 2)
	a.set_xticklabels(labels,rotation=90)
	figure.subplots_adjust(bottom=0.4)
	plt.show()

def visualize2(item1,item2,parsed_data,limit,nombre):
	plt.close('all')
	fig=plt.figure(nombre)
	ax=fig.add_subplot(111,projection='3d')
	cnt=Counter()
	xs=[]
	xlabel=[]
	ys=[]
	ylabel=[]
	zs=[]
	for item in parsed_data:
		cnt[(item[item1],item[item2])]+=1
	limite=dict(cnt.most_common(limit))
	for i in range(len(limite.keys())):
		xlabel.append(limite.keys()[i][0])
		ylabel.append(limite.keys()[i][1])
		xs.append(i)
		ys.append(i)
		zs.append(limite[limite.keys()[i]])
	ax.scatter(xs,ys,zs)
	ax.set_xticklabels(xlabel)
	ax.set_yticklabels(ylabel)
	ax.set_xlabel(item1)
	ax.set_ylabel(item2)
	ax.set_zlabel('incidencias')
	plt.show()

def cronograma(parsed_data,nombre):
	plt.close('all')
	fig=plt.figure(nombre)
	ax=fig.add_subplot(111,projection='3d')
	cnt=Counter()
	xs=[]
	ys=[]
	zs=[]
	for row in parsed_data:
		cnt[(row['Fecha']['dia'],row['Fecha']['hora'])]+=1
	for instance in cnt.keys():
		xs.append(int(instance[0]))
		ys.append(int(instance[1]))
		zs.append(cnt[instance])
	ax.scatter(xs,ys,zs)
	ax.set_xlabel('dia')
	ax.set_ylabel('hora')
	ax.set_zlabel('procesos')
	plt.show()
