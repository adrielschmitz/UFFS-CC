<?php
	if(!(isset($_SESSION['logado']) && $_SESSION['logado'] == true)){
		header("Location: login.php");
	}
	if(isset($_SESSION['logado']) && $_SESSION['logado'] == true):?>
	<div class="container" id="container-minhas-receitas">
		<a href="novareceita.php" class="blue-grey darken-3 waves-effect waves-light btn-large">Nova Receita
			<i class="large material-icons">mode_edit</i>
		</a>
	</div>
<?php endif; ?>
<div class="container">
	<div class="row">
		<?php
		if(isset($_SESSION['logado']) && $_SESSION['logado'] == true):
			$receitas = busca_minhas_receitas_desc($conexao, $_SESSION['id']);
			if($receitas):
				foreach ($receitas as $receita): ?>
						<div class="col s12 m6">
							<div class="card blue-grey darken-2">
								<div class="card-content white-text">
									<span class="card-title"><?php echo $receita['nome'] ?></span>
									<p><?php echo $receita['descricao'] ?></p>
									<a href="receita.php?id=<?php echo $receita['id']?>&action=" class="btn-floating right">	<i class="material-icons">add</i>
									</a>
								</div>
								<div class="card-action"></div>
							</div>
						</div>
		 <?php 
				endforeach; 
			endif;
		endif;
		 ?>
	</div>
</div>