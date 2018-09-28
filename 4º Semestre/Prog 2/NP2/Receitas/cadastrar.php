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
		<?php include "parallax.php"; ?>
		<main>
			<div class="container" id="container-minhas-receitas">
				<form action="salva_dados.php" method="post" enctype="multipart/form-data">
					<div class="row">
						<div class="input-field col s12">
							<input name="nome" id="nome" type="text" class="validate">
							<label for="nome">Nome e Sobrenome</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input name="email" id="email" type="email" class="validate">
							<label for="email">E-mail</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input name="senha" id="senha" type="password" class="validate">
							<label for="senha">Senha</label>
						</div>
					</div>
					<div class="row">
						<div class="input-field col s12">
							<input name="rsenha" id="rsenha" type="password" class="validate">
							<label for="rsenha">Confirme sua Senha</label>
						</div>
					</div>
					<div class="row">
						<div class="file-field input-field">
							<div class="btn">
								<span>Foto</span>
								<input name="imagem" type="file">
							</div>
							<div class="file-path-wrapper ">
								<input class="file-path validate" placeholder="Selecione uma Foto" type="text">
							</div>
						</div>
					</div>
					<button class="btn waves-effect waves-light blue-grey" type="submit" name="action">Cadastrar
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
