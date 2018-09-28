<?php
	class assistente extends usuario{
		protected $codigo;

		public function __construct($nome, $cpf, $endereco,	$codigo){
			parent::__construct($nome, $cpf, $endereco);
			$this->codigo=$codigo;
		}

		function imprimeUsuario(){
			parent::imprimeUsuario();
			echo $this->getCodigo();
			echo "<br/>";
		}

		function getCodigo(){
			return $this->codigo;
		}
		function setCodigo($codigo){
			$this->codigo=$codigo;
		}
	}
?>