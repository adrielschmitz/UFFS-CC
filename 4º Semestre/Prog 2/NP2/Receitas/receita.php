<?php session_start(); require "funcoes.php"; ?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
		<link type="text/css" rel="stylesheet" href="materialize/css/materialize.min.css"  media="screen,projection"/>
		<link type="text/css" rel="stylesheet" href="css/estilo.css">
		<link rel="icon" type="image/jpg" href="img/icone.png">
		<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
	</head>

	<body>
		<?php include "menu.php"; ?>
		<main>
			<?php include "parallax.php"; ?>
			<div class="container">
				<?php
					if(isset($_GET['id'])):
						$receitas = busca_receita($conexao, $_GET['id']);
						if($receitas):
							foreach ($receitas as $receita): ?>
									<div class="col s12 m12">
										<div class="card blue-grey darken-4">
											<div class="card-content white-text">
												<span class="card-title"><?php echo $receita['nome'] ?></span>
												<div class="card-content white-text">
													<span class="card-title">Ingredientes</span>
													<p><?php echo $receita['ingredientes'] ?></p>
													<span class="card-title"></span>
													<span class="card-title">Modo de Preparo</span>
													<p><?php echo $receita['modo_preparo'] ?></p>
												</div>
											</div>
										</div>
									</div>
					<?php 
							endforeach; 
						endif;
					endif;?>
			</div>
		</main>
		<?php include "rodape.php" ?>

		<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
		<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
		<script type="text/javascript" src="js/funcoesjs.js"></script>

	</body>
</html>