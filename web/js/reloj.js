function mueveReloj(){
	var momentoActual = new Date();
	var hora = momentoActual.getHours();
	var minuto = momentoActual.getMinutes();
	var segundo = momentoActual.getSeconds();

	//SEGUNDOS
	var horaSegundos;
	if(segundo < 10){
		horaSegundos = "0" + segundo;
	}else{
		horaSegundos = segundo;
	}

	//minuto
	var minutos = momentoActual.getMinutes();
	var horaMinutos;
	if(minutos < 10){
		horaMinutos = "0" + minutos;
	}else{
		horaMinutos = minutos;
	}

	//HORAS
	var horas = momentoActual.getHours();
	var horaHoras;
	if(horas < 10){
		horaHoras = "0" + horas;
	}else{
		horaHoras = horas;
	}

	document.form_reloj.relojSegundo.value = horaSegundos;
	document.form_reloj.relojMinuto.value = horaMinutos;
	document.form_reloj.relojHora.value = horaHoras;

	setTimeout("mueveReloj()",1000);
}
