<table>
	<tr>
		<th>Nome</th>
		<th>Descrição</th>
		<th>Prazo</th>
		<th>Prioridade</th>
		<th>Concluida</th>
		<th>Opções</th>
	</tr>
	<?php foreach($lista_lembretes as $lembrete): ?>
	<tr>
		<td><?php echo $lembrete['nome']; ?></td>
		<td><?php echo $lembrete['descricao']; ?></td>
		<td><?php echo data_para_exibir($lembrete['prazo']); ?></td>
		<td><?php echo traduz_prioridade($lembrete['prioridade']); ?></td>
		<td><?php echo traduz_concluida($lembrete['concluida']); ?></td>
		<td>
			<a href="editar.php?id=<?php echo $lembrete['id'];?>">Editar</a>
			&nbsp;
			<a href="remover.php?id=<?php echo $lembrete['id'];?>">Remover</a>
		</td>
	</tr>
	<?php endforeach; ?>
</table>