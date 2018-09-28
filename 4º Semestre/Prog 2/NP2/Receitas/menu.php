<header>
		<div id="wrapper">
			<div id="sidebar-wrapper" class="orange darken-3"> <!-- Menu lateral-->
				<ul class="sidebar-nav">
					<li>
						<div id="user-menu">
							<?php 
								if(isset($_SESSION['logado']) && $_SESSION['logado'] == true): ?>
										<img src="img/usuario/<?php echo $_SESSION['avatar']; ?>" class="circle center" id="perfil-sidebar">
										<h6 class="white-text center" id="user-name-sidebar">
										<?php echo $_SESSION['nome'];?>
										</h6>
							<?php else:?>
								<img src="img/usuario/usuariodesconhecido.png" class="circle center" id="perfil-sidebar">
							<?php endif; ?>
						</div>
					</li>
					<li class="divider white"></li> <!-- linha em baixo da foto de perfil -->
					<li class="indent">
						<a class="white-text" href="index.php" >Incio
							<i class="material-icons right">home</i>
						</a>
					</li>
					<li class="indent">
						<a class="white-text master-menu" href="javascript:void(0)">Conta
							<i class="material-icons right">person</i>
						</a>
						<ul class="child-menu orange accent-2"> <!-- opção na barra lateral-->
							<li>
								<a class="white-text" href="conta.php">
									<span>Minha Conta</span>
									<i class="material-icons right">settings</i>
								</a>
							</li>
							<li>
								<?php if(isset($_SESSION['logado']) && $_SESSION['logado'] == true):?>
									<a class="white-text" href="logout.php">
										<span>Logout</span>
										<i class="material-icons right">person</i>
									</a>
								<?php else:?>
									<a class="white-text" href="login.php">
										<span>Login</span>
										<i class="material-icons right">person</i>
									</a>
								<?php endif;?>
							</li>
						</ul>
					</li>
					<li class="indent">
						<a class="white-text master-menu" href="javascript:void(0)">Receitas
							<i class="material-icons right">add</i>
						</a>
						<ul class="child-menu orange accent-2"> <!-- opção na barra lateral-->
							<li>
								<a class="white-text" href="minhasreceitas.php">
									<span>Minhas Receitas</span>
									<i class="material-icons right">person</i>
								</a>
							</li>
							<li>
								<a class="white-text" href="receitasrecentes.php">
									<span>Receitas Recentes</span>
									<i class="material-icons right">person</i>
								</a>
							</li>
						</ul>
					</li>
				</ul>
			</div>
		</div>
	<div class="navbar-fixed">
		<nav>
			<div class="nav-wrapper orange accent-2"> <!-- Nav barra-->
				<a href="index.php" class="brand-logo right">
					<img src="img/logo.png" class="left mini-perfil">
				</a>
				<ul id="nav-mobile" class="left hide-on-med">
					<a href="javascript:void(0)" data-activates="slide-out" id="btn_menu"><i class="material-icons">menu</i></a>
				</ul>
			</div>
		</nav>
	</div>
</header>
