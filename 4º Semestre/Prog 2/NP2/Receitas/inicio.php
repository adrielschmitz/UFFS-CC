<div class="container">
	<br>
	<h5>
		Receitas Recentes
	</h5>
	<div class="row">
		<?php
			$receitas = busca_receitas_desc($conexao);
			foreach ($receitas as $receita):?>
				<div class="col s12 m6">
					<div class="card">
						<div class="card-image">
							<img src="img/receitas/<?php echo $receita['id']?>.png">
							<span class="card-title"><?php echo $receita['nome']?></span>
							<a href="receita.php?id=<?php echo $receita['id']?>&action=" class="btn-floating halfway-fab waves-effect waves-light red"><i class="material-icons">add</i></a>
						</div>
						<div class="card-content">
							<p>
								<?php echo $receita['descricao']?>
							</p>
						</div>
					</div>
				</div>
		<?php endforeach; ?>
	</div>
</div>