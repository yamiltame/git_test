import Tkinter as tk
from Tkinter import *
LARGE_FONT=('Verdana',12)
import matplotlib
matplotlib.use('TkAgg')
from  matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from  matplotlib.figure import Figure
import parser
from parser import *
import graph
from graph import *

class AnalizadorLogs(tk.Tk):
	def __init__(self,*args,**kargs):
		tk.Tk.__init__(self,*args,**kargs)
		contenedor=tk.Frame(self)
		contenedor.pack(side='top',fill='both',expand=True)
		contenedor.grid_rowconfigure(0,weight=1)
		contenedor.grid_columnconfigure(0,weight=1)
		self.frames={}
		for L in (Inicio,Correo,Web,Acceso):
			frame=L(contenedor,self)
			self.frames[L]=frame
			frame.grid(row=0,column=0,sticky='nsew')
		self.show_frame(Inicio)
	def show_frame(self,frameshow):
		frame=self.frames[frameshow]
		frame.tkraise()

class Inicio(tk.Frame):
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		tk.Label(self,text='Analizador de logs').pack(pady=10,padx=10)
		tk.Button(self,text='Analizar correos',command=lambda:controller.show_frame(Correo)).pack()
		tk.Button(self,text='Analizar web',command=lambda:controller.show_frame(Web)).pack()
		tk.Button(self,text='Analizar conexion',command=lambda:controller.show_frame(Acceso)).pack()


class Acceso(tk.Frame):
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		w=Entry(self)
		w.pack()
		w.insert(0,"nombre_archivo")
		#Etiqueta
		tk.Label(self,text='Analizar Acceso').pack(pady=10,padx=10)
		#botones
		tk.Button(self,text='INICIO',command=lambda:controller.show_frame(Inicio)).pack()
		tk.Button(self,text='cronograma',command=lambda:cronograma(secureparse(w.get()),'cronograma'+w.get())).pack()
		tk.Button(self,text='Failed password users',command=lambda:visualize('Usuario',userspass(w.get()),10,'Failed password attempts')).pack()
		tk.Button(self,text='Failed password for root',command=lambda:visualize('ip',rootpass(w.get()),10,'Failed passwords for root')).pack()
		tk.Button(self,text='Error retrieving info',command=lambda:visualize('usuario',errorparse(w.get()),20,'Retrieving info about user')).pack()
		tk.Button(self,text='Authentication error',command=lambda:visualize2('rhost','user',authentication_failure(w.get()),20,'Authentication error')).pack()

class Web(tk.Frame):
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		w=Entry(self)
		w.pack()
		w.insert(0,"nombre_archivo")
		tk.Label(self,text='Analizar web').pack(pady=10,padx=10)
		tk.Button(self,text='INICIO',command=lambda:controller.show_frame(Inicio)).pack()
		tk.Button(self,text='cronograma',command=lambda:cronograma(accessparse(w.get()),'web')).pack()
		tk.Button(self,text='status',command=lambda:visualize('status',accessparse(w.get()),20,'status')).pack()
		tk.Button(self,text='Errores 404',command=lambda:visualize('IP',errores(w.get()),20,'Ip error 404')).pack()
		tk.Button(self,text='IP status 200',command=lambda:visualize('IP',exitos(w.get()),20,'Ip exitos 200')).pack()
		tk.Button(self,text='Refer status 200',command=lambda:visualize('Refer',exitos(w.get()),20,'Refer exitos 200')).pack()

class Correo(tk.Frame):
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		w=Entry(self)
		w.pack()
		w.insert(0,"nombre_archivo")
		tk.Label(self,text='Analizador correos').pack(pady=10,padx=10)
		tk.Button(self,text='INICIO',command=lambda:controller.show_frame(Inicio)).pack()
		tk.Button(self,text='cronograma',command=lambda:cronograma(mailparse(w.get()),'mail')).pack()
		tk.Button(self,text='verification fail ip',command=lambda:visualize('ip',verificationfail(w.get()),20,'verification fail ip')).pack()
		tk.Button(self,text='hostname verification fail',command=lambda:visualize('hostname',verificationfail(w.get()),20,'verification fail hostname')).pack()
		tk.Button(self,text='Enviados postfix/smtp',command=lambda:visualize('correo',smtpsent(w.get()),20,'postfix/smtp enviados')).pack()
		tk.Button(self,text='Recibidos',command=lambda:visualize('emisor',pstfixqmgr(w.get()),20,'postfix/qmgr recividos')).pack()


root=AnalizadorLogs()
root.mainloop()
