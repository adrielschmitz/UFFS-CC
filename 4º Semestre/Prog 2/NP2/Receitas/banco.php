<?php
	$server = "localhost";
	$user = "root";
	$password = "";
	$db = "receitas";

	$conexao = mysqli_connect($server, $user, $password, $db);

	if(mysqli_connect_errno($conexao)){
		echo "Erro ao conectar ao servidor";
		die();
	}

	function busca_minhas_receitas($conexao, $usuario){
		$query = "SELECT * FROM receita WHERE id_usuario = ?";
		$statement = $conexao->prepare($query);
		$statement->bind_param('i', $usuario);
		$statement->execute();
		return $statement->get_result();
	}

	function busca_minhas_receitas_desc($conexao, $usuario){
		$query = "SELECT * FROM receita WHERE id_usuario = ? ORDER BY id DESC";
		$statement = $conexao->prepare($query);
		$statement->bind_param('i', $usuario);
		$statement->execute();
		return $statement->get_result();
	}

	function busca_receitas($conexao){
		$query = "SELECT * FROM receita ORDER BY id LIMIT 4";
		$statement = $conexao->prepare($query);
		$statement->execute();
		return $statement->get_result();
	}

	function busca_receitas_desc($conexao){
		$query = "SELECT * FROM receita ORDER BY id DESC LIMIT 4";
		$statement = $conexao->prepare($query);
		$statement->execute();
		return $statement->get_result();
	}

	function busca_receita($conexao, $id){
		$query = "SELECT * FROM receita WHERE id = ?";
		$statement = $conexao->prepare($query);
		$statement->bind_param('i', $id);
		$statement->execute();
		return $statement->get_result();
	}

	function atualiza_dados($conexao, $id, $dados){
		$query = "UPDATE usuario SET nome=? WHERE id=?";
		$statement = $conexao->prepare($query);
		$statement->bind_param('si', $dados['nome'], $id);
		if($statement->execute()){
			return true;
		}
		return false;
	}

	function atualiza_senha($conexao, $id, $senha){
		$query = "UPDATE usuario SET senha=? WHERE id=?";
		$statement = $conexao->prepare($query);
		$statement->bind_param('si', $senha, $id);
		if($statement->execute()){
			return true;
		}
		return false;
	}

	function busca_usuario_senha($conexao, $email){
		$query = "SELECT * FROM usuario WHERE email = ? LIMIT 1";
		$statement = $conexao->prepare($query);
		$statement->bind_param('s', $email);
		if($statement->execute()){
			$res = $statement->get_result();
			foreach ($res as $value) {
				return $value['senha'];
			}
		}
	}

	function busca_usuario($conexao, $email){
		$query = "SELECT * FROM usuario WHERE email = ?";
		$statement = $conexao->prepare($query);
		$statement->bind_param('s', $email);
		if($statement->execute()){
			return $statement->get_result();
		}
	}

	function salva_receita($conexao, $id, $dados){
		$query = "INSERT INTO receita (id_usuario, nome, descricao, ingredientes, modo_preparo) VALUES (?, ?, ?, ?, ?)";
		$statement = $conexao->prepare($query);
		$statement->bind_param('issss', $id, $dados['nome'], $dados['descricao'], $dados['ingredientes'], $dados['modo_preparo']);
		if($statement->execute()){
			return true;
		}
		return false;
	}

	function cadastrar_usuario($conexao, $dados){
		$query = "INSERT INTO usuario (nome, email, senha, foto) VALUES (?, ?, ?, ?)";
		$statement = $conexao->prepare($query);
		$statement->bind_param('ssss', $dados['nome'], $dados['email'], $dados['senha'], $dados['foto']);
		if($statement->execute())
			return true;

	  return false;
	}

	function busca_ultimo_id_receita($conexao){
		$query = "SELECT id FROM receita ORDER BY id DESC LIMIT 1";
		$statement = $conexao->prepare($query);
		$statement->execute();
		$res = $statement->get_result();
		foreach ($res as $value) {
			return $value['id'];
		}
	}
?>