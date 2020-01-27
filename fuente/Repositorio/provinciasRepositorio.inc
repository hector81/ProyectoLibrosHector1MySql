<?php

class ProvinciasRepositorio
{
    public function devolverProvincias() :array{
		$sql = "SELECT NombreProvincia FROM Provincias;";
		$provincias = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$provincias[]  = $row['NombreProvincia'];
		}		
		return $provincias;
    }//fin metodo

}//fin clase
