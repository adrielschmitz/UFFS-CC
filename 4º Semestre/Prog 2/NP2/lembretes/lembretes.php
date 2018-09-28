<?php 
	session_start();
	include "banco.php";
	include "helper.php";

	$exibir_tabela=1;

	if(isset($_POST['nome']) && ($_POST['nome'] != '')){
		$lembrete = array();
		$lembrete['nome']=addslashes($_POST['nome']);

	
		if(isset($_POST['descricao'])){
			$lembrete['descricao']=addslashes($_POST['descricao']);
		}else{
			$lembrete['descricao']= '';
		}

		if(isset($_POST['prazo']) && validar_data($_POST['prazo'])){
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
			$lembrete['concluida']= 0;
	
		} 
		//$_SESSION['lista_lembretes'][] = $lembrete;
		gravar_lembrete($conexao, $lembrete);
	}
	$lembrete = array(
		'id' => 0,
		'nome' => '',
		'descricao' => '',
		'prazo' => '',
		'prioridade' => 1,
		'concluida' => ''
	);
/*	if(isset($_SESSION['lista_lembretes'])){
		$lista_lembretes = $_SESSION['lista_lembretes']; 
	}else { 
		$lista_lembretes = array();
	}
*/	
	$lista_lembretes = buscar_lembretes($conexao);

	include"template.php";
?>
