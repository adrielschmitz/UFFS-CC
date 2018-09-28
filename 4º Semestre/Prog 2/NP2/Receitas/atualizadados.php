<?php session_start();
	require "funcoes.php";
	$erro = 0;

	if(isset($_SESSION['logado']) && $_SESSION['logado'] == true){
		if(isset($_SESSION['nome'])){
			if(!valida_nome($_SESSION['nome'])){
				$erro = 2;
			}
			$dados = array('nome' => $_SESSION['nome']);
			if(!atualiza_dados($conexao, $_SESSION['id'], $dados)){
				$erro = 1;
			}
		}else if(isset($_SESSION['senha'])){
			if(!verifica_senhas($_SESSION['senha'], $_SESSION['rsenha'])){
				$erro = 3
			}
			if(!atualiza_senha($conexao, $_SESSION['id'], $_SESSION['senha'])){
				$erro = 1;
			}
		}
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
	<div class="container">
		<!-- Modal Structure -->
		<div id="sucesso" class="modal">
			<div class="modal-content">
				<h4>Alterações feitas com sucesso!</h4>
				<p>Você alterou seus dados</p>
			</div>
			<div class="modal-footer">
				<a href="conta.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro_banco" class="modal">
			<div class="modal-content">
				<h4>ERRO!</h4>
				<p>Erro ao tentar salvar os dados no banco!</p>
			</div>
			<div class="modal-footer">
				<a href="conta.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro" class="modal">
			<div class="modal-content">
				<h4>ERRO!</h4>
				<p><?php
					if($erro == 2){
						echo "Nome inválido!<br>Utilize somente letras";
					}else if($erro == 3){
						echo "As senhas não são as mesmas ou a sua senha é muito curta!";
					}
				?></p>
			</div>
			<div class="modal-footer">
				<a href="conta.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
	</div>
	<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
	<script type="text/javascript" src="materialize/js/materialize.min.js"></script>
	<script>
		$(document).ready(function(){
			$('.modal').modal();
			<?php
				if($erro == 0){
					echo "$('#sucesso').modal('open');";
				}else if($erro == 1){
					echo "$('#erro_banco').modal('open');";
				}else{
					echo "$('#erro').modal('open');";
				}
			?>
		});
	</script>
</body>
</html>