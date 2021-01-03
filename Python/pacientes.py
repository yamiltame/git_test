peso=0
edad=0
nombre=''
Paciente=[peso,edad,nombre]
Pacientes=[]

def nuevopaciente():
	peso = input('ingresa peso: ')
	edad = input('ingresa edad: ')
	estatura = input('ingresa estatura: ')
	nombre = input('ingresa nombre: ')
	Pacientes.append([peso,edad,estatura,nombre])

def promedio(dato):
	suma=0.0
	if dato=='peso':
		for Paciente in Pacientes:
			suma=suma+Paciente[0]
	if dato=='edad':
		for Paciente in Pacientes:
			suma=suma+Paciente[1]
	if dato=='estatura':
		for Paciente in Pacientes:
			suma=suma+Paciente[2]
	return suma/len(Pacientes)
