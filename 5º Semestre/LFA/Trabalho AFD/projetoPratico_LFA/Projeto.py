#   UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS - CHAPECÓ                                  #
#   CONTRUÇÃO DE UM AUTÔMATO FINITO DETERMINÍSTICO MÍNIMO E LIVRE DE ÉPSILON TRANSIÇÕES     #
#   ALUNOS: ADRIEL SCHMITZ, LEONARDO GONÇALVES                                              #
#   CIÊNCIA DA COMPUTAÇÃO - 5º FASE, PROFESSOR BRAULIO                                      #
#   DICA DE COMPILAÇÃO: python3 Projeto.py < entrada.in                                     #

def get_tokensExpressao():
    list = []
    while True:
        a = input()
        if a == '':
            break
        list.append(a)
    return list

def add_token(A, token):
    p = 0
    for i in token:
        prod = A[p]
        if prod != '':
            prod += ' '
        prod += i + '<' + str(len(A)) + '>' 
        A[p] = prod
        p = len(A)
        A.append('<'+ str(p) + '> ::=')
    A[len(A)-1] += ' eps'
    return A

def add_er(A, er):
    for i in er:
        p = ''
        for j in i:
            p+= j
            if j == 'S':
                p+= '\''
        if i[1] == 'S':
            prod = A[0]
            prod += p[8:]
            A[0] = prod
        A.append(p)
    return A

def find_epsT(prod, A):
    for i in range(len(A)):
        for j in range(len(prod)):
            if prod[j][0] in A[i] and prod[j][0] != A[i][0]:
                prod[i].append(prod[j][0])
    return prod

def get_prod(p, prod):
    for i in range(len(prod)):
        if prod[i][0] == p:
            return prod[i]
    return []
 
def find_tI(prod):
    flag = True
    while flag:
        flag = False
        for p in prod:
            for i in p:
                prod_i = get_prod(i, prod)
                for j in prod_i:
                    if j not in p:
                        flag = True
                        p.append(j)
    return prod

def clear_epsT(A):
    prod = []
    for i in A:
        prod.append(i[0].split())
    prod = find_epsT(prod, A)
    prod = find_tI(prod)
    for i in range(len(A)):
        p = A[i]
        for j in prod[i]:
            prod_ = get_prod(j, A)
            for k in prod_[2:]:
                if k not in p:
                    p.append(k)
        A[i] = p
    for i in range(len(A)):
        for j in range(len(prod)):
            if prod[j][0] in A[i][2:]:
                A[i].remove(prod[j][0])
    return A

def get_sf(A):
    sf = []
    for i in A:
        for j in i[2:]:
            if j == 'eps' or j == '|':
                continue
            if j[0] not in sf: 
                sf.append(j[0])
    return sf

def create_p(len_sf):
    p = []
    for i in range(len_sf):
        p.append('')
    return p

def fixup_p(prod):
    for i in range(len(prod)):
        if prod[i] == '':
            prod[i] = '-'
        if ' ' in prod[i]:
            p = '-'
            for j in sorted(prod[i]):
                if j == ' ':
                    continue
                p += j
            prod[i] = p
    return prod

def clear_p(prod):
    p = ''
    for i in prod:
        if i == ' ':
            continue
        p += i
    return p

def check_prod(prod, p, test):
    i = '<'
    if test:
        i += '-'
    p = i + p + '>'
    return p in prod

def error_p(n):
    error = ['<->']
    error_p = []
    for i in range(n):
        error_p.append('-')
    error.append(error_p)
    return error

def find_p(producoes_p, producao, A, sf):
    ignore = ['eps', '|', '::=']
    producao = get_prod( producao, A)
    for i in producao[1:]:
        if i in ignore:
            continue
        indice_p = sf.index(i[0])
        if i[2:-1] in producoes_p[indice_p]:
            continue
        if producoes_p[indice_p] != '':
            producoes_p[indice_p] += ' '
        producoes_p[indice_p] += i[2:-1]
    return producoes_p

def find_new_p(producoes_p, fila, prod):
    for i in producoes_p:
        if i == '':
            continue
        if ' ' in i:
            j = True
        else:
            j = False
        if not check_prod(prod, i, j):
            fila.insert(0, i)
    return fila


def determinizacao(A):
    sf = sorted(get_sf(A))
    fila = []
    afd = []
    producoes_AFD = []
    for i in A:
        producoes_AFD.append(i[0])
    for i in A:
        producao = [i[0]]
        if 'eps' in i:
            producao.insert(0, '*')
        producoes_p = create_p(len(sf))
        producoes_p = find_p(producoes_p, i[0], A, sf)
        fila = find_new_p(producoes_p, fila, producoes_AFD)
        producao.append(fixup_p(producoes_p))
        afd.append(producao)
    while fila != []:
        p = fila.pop()
        p_split = p.split()
        p = clear_p(sorted(p))
        if check_prod(producoes_AFD, p, True):
            continue
        p = '<-' + p + '>'
        producoes_AFD.append(p)
        producao = [p]
        producoes_p = create_p(len(sf))
        for i in p_split:
            prod_i = get_prod('<' + i + '>', A)
            if 'eps' in prod_i and '*' not in producao:
                producao.insert(0, '*')
            producoes_p = find_p(producoes_p, '<' + i + '>', A, sf)
        fila = find_new_p(producoes_p, fila, producoes_AFD)
        producao.append(fixup_p(producoes_p))
        afd.append(producao)
    
    afd.append(error_p(len(sf)))
    return afd

def check_p(check, p, AFD):
    check.append(p)
    for i in AFD:
        if  p in i:
            if len(i) == 2:
                producoes = i[1]
            else:
                producoes = i[2]
            break
    for i in range(len(producoes)):
        if '<' + producoes[i] + '>' not in check:
            check += set(check_p(check, '<' + producoes[i] + '>', AFD))
    return check

def minimizacao(AFD):
    check_s = check_p([], '<S>', AFD)
    finais = ['<->']
    for i in AFD:
        if '*' in i:
            finais.append(i[1])
    remove_p = []
    fix_p = []
    for i in range(len(AFD)):
        alcancavel_flag = False
        morto_flag = True
        if len(AFD[i])== 2:
            producao = AFD[i][0]
        else:
            producao = AFD[i][1]
        check_producao = check_p([], producao, AFD)
        for j in finais:
            if j in check_producao:
                morto_flag = False
        if producao in check_s:
            alcancavel_flag = True
        if morto_flag or not alcancavel_flag:
            remove_p.append(i)
            fix_p.append(producao)
    for i in sorted(remove_p, reverse = True):
        AFD.remove(AFD[i])
    for i in range(len(AFD)):
        if len(A[i]) == 2:
            i_p = 1
        else:
            i_p = 2
        producoes = A[i][i_p]
        for j in range(len(producoes)):
            if producoes[j] in fix_p:
                producoes[j] = '-'
        A[i][i_p] = producoes
    return AFD

def print_afd(AFD, A):
    sf = sorted(get_sf(A))
    for i in AFD:
        p = ''
        if '*' in i:
            p += i[1]
            producoes = i[2]
            eps = True
        else:
            p += i[0]
            eps = False
            producoes = i[1]
        p += ' ::= '
        for i in range(len(producoes)):
            flag = True
            p += sf[i] + '<' + producoes[i] + '>'
            if i < len(producoes) - 1 or eps:
                p+= ' | '
        if eps:
            p += 'eps'
        print(p)                           
        
tokens = get_tokensExpressao()
expR = get_tokensExpressao()
A = []
A.append('<S> ::=')

for i in tokens:
    A = add_token(A, i)
A = add_er(A, expR)

for i in range(len(A)):
    A[i] = A[i].split()  
A = clear_epsT(A)

AFD = determinizacao(A)
AFD = minimizacao(AFD)
print_afd(AFD, A)