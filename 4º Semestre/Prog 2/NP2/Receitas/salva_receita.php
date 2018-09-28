<?php session_start(); require "funcoes.php"; 
	if(isset($_SESSION['logado']) && $_SESSION['logado'] == true):
		$nome = troca_caracteres_especiais($_POST['nome']);
		$descricao = troca_caracteres_especiais($_POST['descricao']);
		$ingredientes = troca_caracteres_especiais($_POST['ingredientes']);
		$modo_preparo = troca_caracteres_especiais($_POST['modo_preparo']);
		$imagem = $_FILES;
		$caminho = "img/receitas/";
		$erro = 0;

		if($erro == 0){
			$dados = array('nome' => $nome, 'descricao' => $descricao, 'ingredientes' => $ingredientes, 'modo_preparo' => $modo_preparo);
			if(salva_receita($conexao, $_SESSION['id'], $dados)){
				$id = busca_ultimo_id_receita($conexao);
				if(!mover_imagem($imagem, $caminho, $id)){
					$erro = 2;
				}
			}else{
				$erro = 3;
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
				<h4>Receita Salva</h4>
				<p>Sua receita foi salva com sucesso!</p>
			</div>
			<div class="modal-footer">
				<a href="novareceita.php" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro_texto" class="modal">
			<div class="modal-content">
				<h4>ERRO</h4>
				<?php
					if($erro == 1){
						echo "<p>Somente são permitidos letras, numeros, ' ' ', ' _ ' e ' / '!</p>";
					}else if($erro == 2){
						echo "<p>Não foi possivel mover a imagem, nenhum imagem foi selecionada ou a imagem é muito grande para ser salva!</p>";
					}

				?>
			</div>
			<div class="modal-footer">
				<a href="javascript:window.history.go(-1)" class="modal-action modal-close waves-effect waves-green btn-flat">OK</a>
			</div>
		</div>
		<div id="erro" class="modal">
			<div class="modal-content">
				<h4>ERRO</h4>
				<p>Erro ao tentar salvar os dados no banco!</p>
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
		<script>
			$(document).ready(function(){
				$('.modal').modal();
				$('#sucesso').modal('open');
			});
		</script>
	<?php elseif($erro == 1 || $erro == 2): ?>
		<script>
			$(document).ready(function(){
				$('.modal').modal();
				$('#erro_texto').modal('open');
			});
		</script>
			
	<?php else: ?>
		<script>
			$(document).ready(function(){
				$('.modal').modal();
				$('#erro').modal('open');
			});
		</script>
	<?php endif;
	endif; ?>
		

</body>
</html>