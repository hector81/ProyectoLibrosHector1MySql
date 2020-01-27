<?php

class CiudadesRepositorio
{
    public function comprobarCiudadExisteEnProvincia(string $nombreProvincia, string $nombreCiudad) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $boolExiste = false;
        $sql = "SELECT Ciudades.NombreCiudad AS CIUDAD FROM Ciudades
			JOIN Provincias ON Provincias.IdProvincia = Ciudades.IdProvincia
			WHERE Provincias.NombreProvincia = ?;";   
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$nombreProvincia,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			if($nombreCiudad == $row['CIUDAD']){
				$boolExiste = true;
			}
		}
		$stmt = null;
		$con = null;
		return $boolExiste;
    }//fin metodo
	
    //funcion para sacar el id de una ciudad
    public function sacarIdCiudad(string $nombreProvincia, string $nombreCiudad) :int{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $idCity= 0;
        $sql = "SELECT Ciudades.IdCiudad AS ID_CIUDAD FROM Ciudades
			JOIN Provincias ON Provincias.IdProvincia = Ciudades.IdProvincia
			WHERE Provincias.NombreProvincia = ?
			AND Ciudades.NombreCiudad = ? ;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$nombreProvincia,PDO::PARAM_STR);
		$stmt->bindParam(2,$nombreCiudad,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$idCity == $row['ID_CIUDAD'];
		}
		$stmt = null;
		$con = null;
		return $idCity;
    }//fin metodo

}//fin clase
