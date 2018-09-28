<?php session_start(); require "funcoes.php"; 
	if(!(isset($_SESSION['logado']) && $_SESSION['logado'] == true)){
		header("Location: login.php");
	}
?>

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
				<form method="post" action="atualizadados.php">
					<div class="row">
						<div class="input-field col s12">
							<input name="nome" id="nome" type="text" class="validate">
							<label for="nome">Nome</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input disabled value="werlangleonardo@gmail.com" id="disabled" type="text" class="validate">
							<label for="disabled">Email</label>
						</div>
					</div>
					<button class="btn waves-effect waves-light blue-grey" type="submit" name="action">Salvar Dados
						<i class="material-icons right">send</i>
					</button>
				</form>
			</div>
			<div class="container" id="container-minhas-receitas">
				<form method="post" action="atualizadados.php">
					<div class="row">
						<div class="input-field col s12">
							<input name="senha" id="password" type="password" class="validate">
							<label for="password">Senha</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input id="rpassword" type="password" class="validate">
							<label for="rpassword">Confirme sua senha</label>
						</div>
					</div>
					<button class="btn waves-effect waves-light blue-grey" type="submit" name="action">Atualizar Senha
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
