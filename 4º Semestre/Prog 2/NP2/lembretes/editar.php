<?php 
	session_start();
	include "banco.php";
	include "helper.php";

	$exibir_tabela=0;

	if(isset($_POST['nome']) && ($_POST['nome'] != '')){
		$lembrete= array();
		$lembrete['nome']=addslashes($_POST['nome']);
		$lembrete['id']=$_POST['id'];
	
		if(isset($_POST['descricao'])){
			$lembrete['descricao']=addslashes($_POST['descricao']);
		}else{
			$lembrete['descricao']= '';
		}
		if(isset($_POST['prazo'])){
			$lembrete['prazo'] = data_para_banco($_POST['prazo']);
		}else{
			$lembrete['prazo']= '';
		}

		if(isset($_POST['prioridade'])){
		   $lembrete['prioridade']=$_POST['prioridade'];
		}
		else{
			$lembrete['prioridade'] = 0;
		}   

		if(isset($_POST['concluida'])){
			$lembrete['concluida']='1';
		}else{
			$lembrete['concluida']= '';
	
		} 

		editar_lembrete($conexao, $lembrete);
		header('Location: lembretes.php');
		die();
	}

	$lembrete = buscar_lembrete($conexao, $_GET['id']);

	include"template.php";
?>