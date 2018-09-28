<form method="POST"> 
	<fieldset>
		<input type="hidden" name="id" value="<?php echo $lembrete['id']; ?>" />
		<legend>Novo Lembrete</legend> 
		<label> 
			Nome: <input type="text" name="nome" value="<?php echo $lembrete['nome']; ?>" />
		</label> 
		<label> 
			Descrição:(Opcional) <input type="text" name="descricao" value="<?php echo $lembrete['descricao']; ?>"/>
		</label>
		<label>
			Prazo:(Opcional) <input type="text" name="prazo" value="<?php echo data_para_exibir($lembrete['prazo']); ?>"/>
		</label>
		<label> 
			Prioridade: 
			<input type="radio" value="1" name="prioridade" <?php echo ($lembrete['prioridade'] == 1) ? 'checked' : '';?>/>Baixa
			<input type="radio" value="2" name="prioridade" <?php echo ($lembrete['prioridade'] == 2) ? 'checked' : '';?>/>Média
			<input type="radio" value="3" name="prioridade" <?php echo ($lembrete['prioridade'] == 3) ? 'checked' : '';?>/>Alta
		</label>
		<label> 
			Lembrete Concluido:
			<input type="checkbox" name="concluida" value="1" <?php echo ($lembrete['concluida'] == 't') ? 'checked' : '';?> >
		</label>
	   <input type="submit" value="<?php echo (isset($_GET['id']) > 0) ? "Atualizar" : "Cadastrar";?>" /> 
	</fieldset> 
</form>