$(".button-collapse").sideNav();

$('.collapsible').collapsible();

$('.master-menu').click(function(e){
	e.preventDefault();
	$(this).next('ul').slideToggle();
	$('.child-menu').not($(this).next()).slideUp();
});

$('#btn_menu').click(function(e){
	e.preventDefault();
	$('#wrapper').toggleClass('toggled');
	$('#btn_menu').toggleClass('toggled');

});

$(document).ready(function(){
	$('.parallax').parallax();
});

function callParallax(){
	$('.parallax').parallax();
}


$('.area-texto').val('New Text');

$('.area-texto').trigger('autoresize');

window.load = callParallax;