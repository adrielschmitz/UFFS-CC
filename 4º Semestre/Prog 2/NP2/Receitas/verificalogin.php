<?php
	session_start();
	require "funcoes.php";

	$email = $_POST['email'];
	$senha = $_POST['senha'];

	$usuario = verifica_login($conexao, $email, $senha);
	if($usuario){
		$_SESSION['logado'] = true;
		$usuario = busca_usuario($conexao, $email);
		foreach ($usuario as $usuarios) {
			$_SESSION['id'] = $usuarios['id'];
			$_SESSION['nome'] = $usuarios['nome'];
			$_SESSION['avatar'] = $usuarios['foto'];
		}
		header('Location: index.php');
	}else if(true):?>

<!DOCTYPE html>
<html>
<head>
		<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
		<link type="text/css" rel="stylesheet" href="materialize/css/materialize.min.css"  media="screen,projection"/>
		<link type="text/css" rel="stylesheet" href="css/estilo.css">
		<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
</head>
<body>
	<div class="container">
		<div id="erro" class="modal">
			<div class="modal-content">
				<h4>Email ou Senha incorretos</h4>
				<p>Tente novamente</p>
			</div>
			<div class="modal-footer">
				<a href="login.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
	</div>
	<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
	<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
	<script>
		$(document).ready(function(){
			$('.modal').modal();
			$('#erro').modal('open');
		});
	</script>
</body>
</html>

<?php endif;?>