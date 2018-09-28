<?php session_start(); require "funcoes.php";?>

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
			<?php include "inicio.php" ?>
		</main>
		<?php include "rodape.php" ?>

		<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
		<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
		<script type="text/javascript" src="js/funcoesjs.js"></script>

	</body>
</html>