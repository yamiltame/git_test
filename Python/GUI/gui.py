from Tkinter import *


root = Tk()
def shit():
	Label(root,text='GOLFA').pack()

root.title("Simulador de Moduladores")
Button(root,text="Crear diagrama",command=shit).pack()
root.mainloop()
