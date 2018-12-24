#DICA DE COMPILAÇÃO: $python3 recorrencias.py
#Resultado salvo em um arquivo com o nome out.txt

with open('out.txt', 'w') as file:
	file.write('UNIVERSIDADE FEDERAL DA FRONTEIRA SUL\nMATEMÁTICA DISCRETA\nADRIEL SCHMITZ, MATRÍCULA: 1611100047')

dia = int(input('Informe o dia do seu aniversário\n-> '))
mes = int(input('Informe o último número do mes do seu aniversário (Ex: 12, informa o 2)\n-> '))
ano = int(input('Informe o último número do ano do seu aniversário (Ex: 1990, informa o 0)\n-> '))
parteGenericaFormula = 'an = (6*an−1) − (12*an−2) + (8*an−3) + '

def chamaRecorrencia():
	for i in range(0, 6):
		vet = [dia, mes, ano]
		writeHeader(i, vet)
		for n in range(3, 13):
			writeN(i, n, vet)
		del vet

def writeN(i, n, vet):
	with open('out.txt', 'a') as file:
		aux = forms(i, n, vet)
		vet[0] = vet[1]
		vet[1] = vet[2]
		vet[2] = aux
		file.write(str(n) + ' = ' + str(vet[2]) + '\n')

def forms(i, n, vet):
	if i == 0:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + (n * (3 ** n))
	elif i == 1:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + (n * (2 ** n))
	elif i == 2:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + ((n ** 2) * (3 ** n))
	elif i == 3:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + ((n ** 2) * (2 ** n))
	elif i == 4:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + ((n ** 2 + 2 * n - 1) * 3 ** n)
	elif i == 5:
		return (6 * vet[2]) - (12 * vet[1]) + (8 * vet[0]) + ((n ** 2 + 2 * n - 1) * 2 ** n)

def writeHeader(i, vet):
	with open('out.txt', 'a') as file:
		if i == 0:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '(n*3ˆn)\n')
		elif i == 1:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '(n*2^n)\n')
		elif i == 2:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '(n²) * (3ˆn)\n')
		elif i == 3:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '(n² * 2ˆn)\n')
		elif i == 4:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '((n²+2 * n−1) * 3ˆn)\n')
		elif i == 5:
			file.write('\n\n' + '(' + chr(ord('a')+i) + ') ' + parteGenericaFormula + '((n²+2 * n−1) * 2ˆn)\n')

		for i, posicao in enumerate(vet): #escreve no arquivo
			file.write(str(i) + ' = ' + str(posicao) + '\n')

chamaRecorrencia()
print('Resultado no arquivo out.txt')
