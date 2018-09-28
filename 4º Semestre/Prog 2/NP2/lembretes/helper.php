<?php
function traduz_prioridade($codigo){
  $prioridade = '-';
  switch($codigo){
     case 1:
        $prioridade='Baixa';
        break;
     case 2:
        $prioridade='Média';
        break;
     case 3:
        $prioridade='Alta';
        break;
  }
  return $prioridade;
}

function data_para_banco($data){
  if($data==""){
    return"";
  }
  $dados = explode('/', $data);
  $dataBanco = "{$dados[2]}-{$dados[1]}-{$dados[0]}";
  return $dataBanco;
}

function data_para_exibir($data){
  if($data=="" || $data=="0000-00-00"){  
    return ""; 
  }
  $dados = explode('-', $data);
  $dataExibir = "{$dados[2]}/{$dados[1]}/{$dados[0]}";
  return $dataExibir;
}

function traduz_concluida($concluida) {
  if ($concluida == 1) {
    return 'Sim';
  }
  return 'Não';
}

function validar_data($data) {
  $padrao = '/^[0-9]{1,2}\/[0-9]{1,2}\/[0-9]{4}$/';
  $resultado = preg_match($padrao, $data);
  if (! $resultado) {
    return false;
  }
  $dados = explode('/', $data);
  $dia = $dados[0]; $mes = $dados[1];
  $ano = $dados[2];
  $resultado = checkdate($mes, $dia, $ano);
  return $resultado;
}
?>