<?php
	include "banco.php";
	if(is_numeric($_GET['id'])){
		remover_lembrete($conexao, $_GET['id']);
	}
	header('Location: lembretes.php');
	die();
?>