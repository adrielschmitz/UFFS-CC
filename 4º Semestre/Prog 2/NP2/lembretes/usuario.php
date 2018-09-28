<?php
	class usuario{
		public $nome;
		private $cpf;
		protected $endereco;
		public static $usuariosOnline = 0;

		public function __construct($nome, $cpf='', $endereco=''){
			$this->nome = $nome;
			$this->cpf = $cpf;
			$this->endereco = $endereco;
			self::alteraNroUsuariosOnline();
		}

		function getEndereco(){
			return $this->endereco;
		}
		function setEndereco($endereco){
			$this->endereco=$endereco;
		}

		function getNome(){
			return $this->nome;
		}
		function setNome($nome){
			$this->nome=$nome;
		}

		function getCpf(){
			return $this->cpf;
		}
		function setCpf($cpf){
			$this->cpf=$cpf;
		}

		function imprimeUsuario(){
			echo "Bem Vindo, ".$this->nome."<br/>";
			echo $this->getCpf()."<br/>";
			echo $this->getEndereco()."<br/>";
		}

		function alteraNroUsuariosOnline(){
			self::$usuariosOnline++;
		}

		function controlarUsuariosOnline($valor){
			self::$usuariosOnline+=$valor;
		}
	}
?>