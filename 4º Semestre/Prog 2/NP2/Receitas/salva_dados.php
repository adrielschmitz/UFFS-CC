<?php session_start(); require "funcoes.php";
	if($_POST['nome']):
		$erro = 0;
		$nome = troca_caracteres_especiais($_POST['nome']);
		$email = troca_caracteres_especiais($_POST['email']);
		$senha= troca_caracteres_especiais($_POST['senha']);
		$rsenha = troca_caracteres_especiais($_POST['rsenha']);
		$imagem = $_FILES;
		$caminho = 'img/usuario/';
		$foto = remove_pontos($email);
		$foto = $foto.'.png';
		if(!verifica_nome($nome)){
			$erro = 1;
		}else if(!verifica_email($email)){
			$erro = 2;
		}else if(!verifica_senhas($senha, $rsenha)){
			$erro = 3;
		}
		if($erro == 0){
			$dados = array('nome' => $nome, 'email' => $email, 'senha' => criptografa_senha($senha), 'foto' => $foto);
			if(mover_imagem($imagem, $caminho, remove_pontos($email))){
				if(!cadastrar_usuario($conexao, $dados)){
					$erro = 4;
				}
			}else{
				$erro = 5;
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
		<div id="sucesso" class="modal">
			<div class="modal-content">
				<h4>Cadastro Realizado</h4>
				<p>Seus dados foram salvos com sucesso!</p>
			</div>
			<div class="modal-footer">
				<a href="login.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro_banco" class="modal">
			<div class="modal-content">
				<h4>ERRO</h4>
				<p>Erro ao tentar salvar os dados no banco!</p>
			</div>
			<div class="modal-footer">
				<a href="javascript:window.history.go(-1)" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro_texto" class="modal">
			<div class="modal-content">
				<h4>ERRO</h4>
				<?php
					if($erro == 1){
						echo "<p>Somente são permitidos letra, espaços e ' no nome!</p>";
					}else if($erro == 2){
						echo "<p>Formato de Email inválido!</p>";
					}else if($erro == 3){
						echo "<p>As senhas não são as mesmas ou a sua senha é muito curta!</p>";
					}else if($erro == 5){
						echo "<p>Não foi possivel mover a imagem, nenhum imagem foi selecionada ou a imagem é muito grande para ser salva!</p>";
					}

				?>
			</div>
			<div class="modal-footer">
				<a href="javascript:window.history.go(-1)" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
	</div>
	<script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
	<script type="text/javascript" src="materialize/js/materialize.min.js"></script>

<?php

		if($erro == 0):?>
			<script type="text/javascript">
				$(document).ready(function(){
					$('.modal').modal();
					$('#sucesso').modal('open');
				});
			</script>
		<?php elseif($erro == 4): ?>
			<script type="text/javascript">
				$(document).ready(function(){
					$('.modal').modal();
					$('#erro_banco').modal('open');
				});
			</script>
		<?php else: ?>
			<script type="text/javascript">
				$(document).ready(function(){
					$('.modal').modal();
					$('#erro_texto').modal('open');
				});
			</script>
		<?php endif;
	endif; ?>

</body>
</html>