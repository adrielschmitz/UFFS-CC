<?php session_start(); require "funcoes.php"; ?>

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
			<div class="container" id="container-minhas-receitas">
				<form method="post" action="verificalogin.php">
					<div class="row">
						<div class="input-field col s12">
							<input name="email" id="nome" type="text" class="validate">
							<label for="nome">Email</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input name="senha" id="senha" type="password" class="validate">
							<label for="senha">Senha</label>
						</div>
					</div>
					<a href="cadastrar.php" class="waves-effect waves-light btn blue-grey">Cadastrar<i class="material-icons left">create</i></a>
					<button class="btn waves-effect waves-light blue-grey" type="submit" name="action">Logar
						<i class="material-icons right">send</i>
					</button>
				</form>
			</div>
		</main>
		<?php include "rodape.php" ?>


		<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
		<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
		<script type="text/javascript" src="js/funcoesjs.js"></script>
	</body>
</html>
