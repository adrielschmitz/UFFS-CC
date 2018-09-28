###############################################################################

def create_file(file_name):
    try:
        file = open(file_name, 'r+b')
        file.close()
        return False
    except FileNotFoundError:
        file = open(file_name, 'w+b')
    file.close()
    return True

###############################################################################

def create_header(file_name):
    _file = open(file_name, 'w+b')
    page_size = 8*1024
    pd_lower = 4
    pd_upper = page_size
    _file.write(pd_lower.to_bytes(2, 'little')) 
    _file.write(pd_upper.to_bytes(2, 'little')) 
    free_space = pd_upper - pd_lower
    _file.write(bytes(free_space))
    _file.close()

###############################################################################

def insert_metapage(meta_page):
    with open('metapage.dat', 'r+b') as _file:
        _file.seek(0, 2)
        table_name = meta_page[0]
        table_name_size = len(table_name)
        meta_page.remove(table_name)
        _file.write(table_name_size.to_bytes(2, 'little'))
        _file.write(table_name.encode())
        for i in meta_page:
            if type(i) is int:
                _file.write(i.to_bytes(2, 'little')) 
            else:
                _file.write(i.encode())
        _file.write('\n'.encode())
        _file.close()

###############################################################################
 
def symbols_remove(data):
    symbols = ';)],'
    for i in symbols:
        if data.find(i) != -1: 
            data = data[:-1] 
    return data
            
###############################################################################

def create_table(command):
    itens = command.split() 
    table_name = itens[0]
    if table_name.find('(') != -1:
        table_name = table_name[:table_name.find('(')]
    if create_file(table_name + "0.dat"):
        create_header(table_name + "0.dat")
    else:
        print("This table has already been inserted")
        return
    meta_page = []
    while itens != []: 
        flag = False
        item_name = itens.pop()
        if item_name.find('(') != -1:
            item_name = item_name[:-1]
            continue
        item_type = itens.pop()
        item_name = symbols_remove(item_name)
        item_type = symbols_remove(item_type)
        if item_type.find('[') != -1:
            flag = True
            item_type_ = item_type.split('[')
            if item_type[0] == 'c':
                item_type_[0] = '1'
            else:
                item_type_[0] = '2'
        if flag:
            meta_page.insert(0, int(item_type_[0]))
            meta_page.insert(1, int(item_type_[1]))
        else:
            meta_page.insert(0, 0)
            meta_page.insert(1, 0)
        meta_page.insert(2, len(item_name))
        meta_page.insert(3, item_name)
    meta_page.insert(0, table_name)
    insert_metapage(meta_page)

###############################################################################

def bt_int(byte_string):
    return int.from_bytes(byte_string, byteorder='little')

###############################################################################

def read_metapage(insert_name):
    with open('metapage.dat', 'r+b') as _file:
        table_name = ''
        while(insert_name != table_name):
            line = _file.readline()
            table_name_len = bt_int(line[:2])
            table_name = line[2:(2 + table_name_len)].decode()
        offset = 2 + table_name_len
        data = []
        while offset < len(line)-1:
            var_type = bt_int(line[offset: offset + 2])
            data.append(var_type)
            if var_type == 0:
                offset  +=  4
            else:
                offset  +=  2
                var_max_size = bt_int(line[offset: offset + 2])
                data.append(var_max_size)
                offset  +=  2
            var_name_len = bt_int(line[offset: offset + 2])
            offset  +=  2
            var_name = line[offset: offset + var_name_len].decode()
            offset  +=  var_name_len
            data.append(var_name)
        return data
    
###############################################################################

def create_space_string(n):
    if n == 0:
        return ''
    return create_space_string(n -1) + ' '

###############################################################################

def insert_table(table_name, item, input_data, input_len):
    id = 0
    file = open(table_name + str(id) + '.dat', 'r+b')
    while True:
        file.seek(0, 0)
        pd_lower = bt_int(file.read(2))
        pd_upper = bt_int(file.read(2))
        free_space = pd_upper - pd_lower
        if free_space >= input_len:
            break
        file.close()
        id += 1
        if create_file(table_name + str(id) + '.dat'):
            create_header(table_name + str(id) + '.dat')
        file = open(table_name + str(id) + '.dat', 'r+b')
    pd_upper -= input_len 
    file.seek(2, 0) 
    file.write(pd_upper.to_bytes(2, 'little')) 
    file.seek(pd_lower, 0)  
    file.write(pd_upper.to_bytes(2, 'little'))
    for i in item:
        file.write(i.to_bytes(2, 'little'))
    pd_lower = file.tell()
    file.seek(0, 0)
    file.write(pd_lower.to_bytes(2, 'little')) 
    file.seek(pd_upper, 0)
    for i in input_data:
        if type(i) is int:
            file.write(i.to_bytes(4, 'little')) 
        else:
            file.write(i.encode())
    file.close()

###############################################################################

def insert_into(command):
    command_ = command.split()
    table_name = command_[0]
    if table_name.find('(') != -1:
        table_name = table_name[:-1]
    data = read_metapage(table_name)
    input_ = command[command.find('(') + 2:]
    input_ = input_.split()
    data_offset = 0
    input_len = 0
    item = [0]
    input_data = []
    for i in range( len(input_)):
        data_type = data[data_offset]
        data_name = symbols_remove(input_[i])
        if data_type == 0:
            input_len  +=  4
            input_data.append(int(data_name))
            data_offset  +=  2
            item.append(0)
            item[0]  +=  1
        else:
            if data_type == 1:
                data_name = create_space_string(data[data_offset + 1] - len(data_name)) + data_name
            item.append(len(data_name))
            input_len  +=  len(data_name)
            item[0]  +=  1
            data_offset  +=  3
            input_data.append(data_name)
    insert_table(table_name, item, input_data, input_len)

###############################################################################

def page_print(table_name, item_size):
    file = open(table_name, 'r+b')
    file.seek(0, 0)
    pd_lower = file.read(2)
    pd_lower = bt_int(pd_lower)
    i = 4
    while i < pd_lower:
        file.seek(i)
        tuple = []
        tuple_offset = bt_int(file.read(2))
        tuple_itens_num = bt_int(file.read(2))
        i += 4 + 2*item_size
        if tuple_itens_num == 0:
            continue
        for j in range(tuple_itens_num):
            tuple.append(bt_int(file.read(2)))
        file.seek(tuple_offset, 0)
        out = []
        for k in tuple:
            if k == 0:
                aux = bt_int(file.read(4))
            else:
                aux = file.read(k)
                aux = aux.decode()
            out.append(aux)
        print(out)
    file.close()

##############################################################################

def select_all(table_name):
    data = read_metapage(table_name)
    item_size = int(0)
    i = 0
    while i < len(data):
        if data[i] == 0:
            i  +=  2
        else:
            i  +=  3
        item_size += 1        
    num = int(0)
    while True:
        try:
            file = open(table_name + str(num) + '.dat', 'r+b')
            num += 1
        except FileNotFoundError:
            break
        file.close()
    for i in range(num):
        page_print(table_name + str(i) + '.dat', item_size)

##############################################################################

def delete_where(table_name, id_, id_index, count):
    id = int(0)
    while True:
        try:
            file_name = table_name + str(id) + '.dat' 
            file = open(file_name, 'r+b') 
            id += 1 
            file.seek(0, 0) 
            pd_lower = bt_int(file.read(2)) 
            offset_itens = int(4) 
            while offset_itens < pd_lower:
                file.seek(offset_itens, 0)
                offset = bt_int(file.read(2)) 
                valida = bt_int(file.read(2))
                if valida != 0:  
                    move = int(0) 
                    while move < id_index: 
                        offset  +=  bt_int(file.read(2))
                        move += 1
                    file.seek(offset, 0) 
                    aux = bt_int(file.read(4))
                    if aux == id_: 
                        file.seek(offset_itens + 2, 0)
                        zero = int(0)
                        file.write(zero.to_bytes(2, 'little'))
                offset_itens  +=  4 + count*2
        except FileNotFoundError:
            break

##############################################################################

def delete_from(command):
    table_name = command[0]
    id_ = int(command[4])
    data = read_metapage(table_name)
    i = int(0)
    count = int(0)
    while i < len(data):
        if data[i] != 0:
            i += 3
            count += 1
        elif data[i+1] == 'id':
            count += 1
            id_find = i
            i += 2
    delete_where(table_name, id_, id_find, count)

##############################################################################

create_file('metapage.dat')
while True:
    command = input()
    command_ = command.upper()
    if command_[0:12] == 'CREATE TABLE':
        create_table(command[13:])
    elif command_[0:11] == 'INSERT INTO':
        insert_into(command[12:])
    elif command_[0:11] == 'DELETE FROM':
        delete_from(command[12:].split())
    elif command_[0:13] == 'SELECT * FROM':
        print('')
        select_all(command[14:])
    elif command_[0:5] == 'EXIT':
        break