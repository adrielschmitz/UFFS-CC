<?php session_start(); require "funcoes.php" ?>

<!DOCTYPE html>
<html>
	<head>
		<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
		<link type="text/css" rel="stylesheet" href="materialize/css/materialize.min.css"  media="screen,projection"/>
		<link type="text/css" rel="stylesheet" href="css/estilo.css">
		<link rel="icon" type="image/jpg" href="img/icone.png">
		<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
	</head>

	<body>
		<?php include "menu.php"; ?>
		<main>
			<?php include "parallax.php" ?>
			<div class="container">
				<br>
				<h5>
					Ultimas receitas cadastradas
				</h5>
				<div class="row">
					<?php 
						$receitas = busca_receitas_desc($conexao);
						if($receitas):
							foreach ($receitas as $receita): ?>
								<div class="col l6 s12 m6">
									<div class="card blue-grey darken-2">
										<div class="card-content white-text">
											<span class="card-title"><?php echo $receita['nome'] ?></span>
											<p><?php echo $receita['descricao'] ?></p>
										<a href="receita.php?id=<?php echo $receita['id']?>&action=" class="btn-floating right">	<i class="material-icons">add</i>
										</a>
										</div>

									<div class="card-action">
									</div>
									</div>
								</div>
					<?php 
							endforeach; 
						endif;?>
				</div>
			</div>
		</main>
		<?php include "rodape.php" ?>

		<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
		<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
		<script type="text/javascript" src="js/funcoesjs.js"></script>

	</body>
</html>