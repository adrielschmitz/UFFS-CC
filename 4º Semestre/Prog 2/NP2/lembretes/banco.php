<?php
$bdServidor = '127.0.0.1';
$bdUsuario = 'root';
$bdSenha = '';
$bdBanco = 'lembrador';

$conexao= mysqli_connect($bdServidor, $bdUsuario, $bdSenha, $bdBanco);

if(mysqli_connect_errno($conexao)){
  echo "Problemas para conectar o banco. Erro: ";
  echo mysqli_connect_error();
  die();
}

function buscar_lembretes ($conexao){
  $sqlBusca = 'SELECT * FROM lembretes';
  $resultado = mysqli_query($conexao,$sqlBusca);
  $lembretes = [];
  while ($lembrete = mysqli_fetch_assoc($resultado)) {
    $lembretes[] = $lembrete;
  }
  return $lembretes;
}

function gravar_lembrete ($conexao, $lembrete){
  $sqlInsert = "INSERT INTO 
  lembretes(nome, descricao, prioridade, prazo, concluida) 
  VALUES ('{$lembrete['nome']}',
      '{$lembrete['descricao']}', 
      '{$lembrete['prioridade']}',
      '{$lembrete['prazo']}',
      '{$lembrete['concluida']}'
      )";
  if(mysqli_query($conexao, $sqlInsert)){
    echo mysqli_connect_error($conexao);
  }
}

function editar_lembrete($conexao, $lembrete) {
  $sqlEditar = " UPDATE lembretes SET
  nome = '$lembrete[nome]',
  descricao = '$lembrete[descricao]',
  prioridade = '$lembrete[prioridade]',
  prazo = '$lembrete[prazo]',
  concluida = '$lembrete[concluida]'
  WHERE id = $lembrete[id]";
  mysqli_query($conexao, $sqlEditar);
}

function remover_lembrete($conexao, $id){
  $sqlRemover = "DELETE FROM lembretes WHERE id=".$id;
  mysqli_query($conexao, $sqlRemover);
}

/*function buscar_lembrete($conexao, $id){
  $sqlBusca = 'SELECT * FROM lembretes WHERE id = ' . $id;
  $resultado = mysqli_query($conexao, $sqlBusca);
  return mysqli_fetch_assoc($resultado); 
}*/

function buscar_lembrete ($conexao, $id){
  $sqlBusca = "SELECT * FROM lembretes WHERE id = ? "; // ? significa que ali vai um parâmetro
  $statement = $conexao->prepare($sqlBusca);
  $statement->bind_param("i", $id); // "i" significa um parametro do tipo inteiro
  $statement->execute();
  $resultado = $statement->get_result();
  return $resultado->fetch_assoc();
}

?>