<?php
	require "banco.php";

	function verifica_nome($nome){
		if(preg_match('/[^a-z0-9\ \'\\áàâãäéèêëíìîïóòôõöúùûü]/i', $nome)){
			return false;
		}
		return true;
	}

	function troca_caracteres_especiais($texto){
		$texto = addslashes($texto);
		$texto = str_replace('//', '/', $texto);
		$texto = htmlspecialchars($texto);
		$texto = nl2br($texto);
		return $texto;
	}

	function mover_imagem($imagem, $caminho, $id){
		$types = array('image/jpg', 'image/jpeg');
		if(in_array($imagem['imagem']['type'], $types)){
			if(move_uploaded_file($imagem['imagem']['tmp_name'], $caminho.$id.'.png')){
				return true;
			}
		}
		return false;
	}

	function verifica_email($email){
		if (!filter_var($email, FILTER_VALIDATE_EMAIL)){
			return false;
		}
		return true;
	}

	function remove_pontos($texto){
		return str_replace('.', '', $texto);
	}

	function verifica_senhas($senha, $rsenha){
		if(strlen($senha) < 5){
			return false;
		}
		if(strcmp($senha, $rsenha)){
			return false;
		}
		return true;
	}

	function gerar_string_aleatoria(){
		$texto = '';
		for($i = 0; $i < 22; $i++){
			$c = rand(0, 2);
			if($c == 0){
				$texto = $texto.chr(rand(65, 90));
			}else if($c == 1){
				$texto = $texto.chr(rand(97, 122));
			}else{
				$texto = $texto.chr(rand(48, 57));
			}
		}
		return $texto;
	}

	function criptografa_senha($senha){
		$custo = '08';
		$salt = gerar_string_aleatoria();
		return crypt($senha, '$2a$'.$custo.'$'.$salt.'$');
	}


	function verifica_senha_banco($conexao, $senha, $senha_bd){
		if (crypt($senha, $senha_bd) == $senha_bd) {
			return true;
		} else {
			return false;
		}
	}

	function verifica_login($conexao, $email, $senha){
		$senha_bd = busca_usuario_senha($conexao, $email);
		echo $senha_bd;
		if(verifica_senha_banco($conexao, $senha, $senha_bd)){
			return true;
		}
		return false;
	}

	function valida_nome($nome){
		if(empty($nome) || strlen($nome) > 50){
			return false;
		}
		$array = explode(" ", $nome);
		$i = 0;
		foreach ($array as $value) {
			$i++;
			if(!preg_match('/[a-z\'\\áàâãäéèêëíìîïóòôõöúùûü]{2,}/i', $value)){
				return false;
			}
		}
		if($i < 2){
			return false;
		}
		return true;
	}
?>