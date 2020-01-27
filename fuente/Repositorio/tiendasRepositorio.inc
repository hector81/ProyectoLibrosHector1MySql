<?php

class TiendasRepositorio
{
	public function devolverTiendaInicial() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/tiendas.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT IdTienda, Nombre, IdCiudad, Telefono ,Direccion,ImagenTienda , Activo FROM Tiendas WHERE IdTienda LIKE 1;";
		$tienda =[];
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$tienda[] = new Tiendas($row);
		}
		$con = null;
		$stmt = null;
		return $tienda;
	}//fin metodo

	public function devolverCiudadTienda(int $idTienda) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Ciudades.NombreCiudad FROM Tiendas
				JOIN Ciudades ON Ciudades.IdCiudad = Tiendas.IdCiudad
				WHERE Tiendas.IdTienda = ? ;";
		$ciudad ='';
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$ciudad = $row['NombreCiudad'];
		}
		$con = null;
		$stmt = null;
		return $ciudad;
	}//fin metodo

	public function devolverArrayCiudadProvincias(array $tiendaTotal) :array{
		$arrayCiudadProvincias = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT Provincias.NombreProvincia, Ciudades.NombreCiudad FROM Tiendas
					JOIN Ciudades ON Ciudades.IdCiudad = Tiendas.IdCiudad
					JOIN Provincias ON Provincias.IdProvincia = Ciudades.IdProvincia
					WHERE Tiendas.IdTienda =   ?";
		foreach ($tiendaTotal as $key => $value) {
			$id  = (int)$value->getIdTienda();
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$arrayCiudadProvincias[] = [
					'NombreCiudad' => $row['NombreCiudad'],
					'NombreProvincia' => $row['NombreProvincia']
				];
			}
			$stmt =null;
			$con=null;
		}
		return $arrayCiudadProvincias;
	}//fin metodo

	public function devolverTiendasTotales() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/tiendas.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT IdTienda, Nombre, IdCiudad, Telefono ,Direccion,ImagenTienda, Activo FROM Tiendas   ORDER BY Nombre ASC;";
		$tienda =[];
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$tienda[] = new Tiendas($row);
		}
        $con = null;
        $stmt = null;
		return $tienda;
	}//fin metodo

	public function devolverTiendaIndividual(int $idTienda) :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/tiendas.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT IdTienda, Nombre, IdCiudad, Telefono ,Direccion,ImagenTienda, Activo FROM Tiendas WHERE IdTienda = ?;";
		$tienda =[];
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$tienda[] = new Tiendas($row);
		}
		$con = null;
		$stmt = null;
		return $tienda;
	}//fin metodo

	//esta funcion borra una tienda según el id de tienda que le pasemos
	public function borrarTienda(int $idTienda) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con1 = (new ConexionBaseDatos)->getConexion();
		$sql1 = "DELETE FROM Almacen WHERE IdTienda = ?;";
		$boolTienda1 =false;
		//primero borramos del almacen
		try{
			$con1->beginTransaction();
			$stmt1 = $con1->prepare($sql1);
			$stmt1->bindParam(1,$idTienda,PDO::PARAM_INT);
			if($stmt1->execute()){
				$boolTienda1 =true;
			}
			$con1->commit();
		}catch(PDOException $ex){
			throw $ex;
			$con1->rollBack();
		}finally{
			$con1 = null;
			$stmt1 = null;
		}
		//y luego borramos la tiendas
		$con2 = (new ConexionBaseDatos)->getConexion();
		$sql2 = "DELETE FROM Tiendas WHERE IdTienda = ?;";
		$boolTienda2 =false;
		//primero borramos del almacen
		try{
        $con2->beginTransaction();
        $stmt2 = $con2->prepare($sql2);
        $stmt2->bindParam(1,$idTienda,PDO::PARAM_INT);
        if($stmt2->execute()){
            $boolTienda2 =true;
        }
        $con2->commit();
		}catch(PDOException $ex){
		  throw $ex;
		  $con2->rollBack();
		}finally{
		  $con2 = null;
		  $stmt2 = null;
		}
		$boolTienda3 =false;
		if($boolTienda1 && $boolTienda2){
			$boolTienda3 =true;
		}
		return $boolTienda3;
	}//fin metodo

	public function insertarImagenYsacarRutaImagen(string $name,string $type, string $tmp_name,string $error,string $size) :array{
        //Subimos imagen cargando con ajax
        $valid_extensions = array('jpeg', 'jpg', 'png', 'gif', 'bmp'); // valid extensions
        $path = 'C:/xampp/htdocs/ProyectoLibrosHector1/Imagenes/ImagenesTienda/'; // upload directory

        if(isset($name) && isset($type) && isset($tmp_name) && isset($error) && isset($size))
        {
         // get uploaded file's extension
         $ext = strtolower(pathinfo($name, PATHINFO_EXTENSION));
         // can upload same image using rand function
         $final_image = rand(1000,1000000).$name;

         // comprobamos que sea un formato valido
         if(in_array($ext, $valid_extensions))
         {
          $path = $path.strtolower($final_image);
          //este metodo mueve la foto al fichero
          move_uploaded_file($tmp_name,$path);
         }
         else
         {
          echo 'invalid file';
         }
        }
        //////////////////FIN introduccion IMAGEN //////////////////
        $elementos = array('imagen' => $final_image, 'tipo' => $type);
        return $elementos;
	}//fin metodo

	public function insertarTiendaModificada(array $subirFoto,string $nombreTienda,int $municipio,string $telefonoTienda,
		string $direccionTienda,int $idTienda) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "UPDATE Tiendas SET Nombre = ?, IdCiudad = ?,Telefono = ?,Direccion = ?,ImagenTienda = ? WHERE IdTienda = ?;";
        $boolTienda = false;
        try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nombreTienda,PDO::PARAM_STR);
            $stmt->bindParam(2,$municipio,PDO::PARAM_INT);
            $stmt->bindParam(3,$telefonoTienda,PDO::PARAM_STR);
            $stmt->bindParam(4,$direccionTienda,PDO::PARAM_STR);
            ////PARA LA imagen
            $fotoF = $subirFoto['imagen'];//string
            $tipo = $subirFoto['tipo'];//string
            $rutaImagenSubida = 'Imagenes/ImagenesTienda/'.$fotoF;
            if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
                $stmt->bindParam(5,$rutaImagenSubida,PDO::PARAM_STR);
            }
            $stmt->bindParam(6,$idTienda,PDO::PARAM_STR);
            if($stmt->execute()){
                $boolTienda = true;
            }
            $con->commit();
            return $boolTienda;
        }catch(PDOException $ex){
          throw $ex;
          $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo

	public function insertarTiendaModificadaSinFoto(string $nombreTienda,int $municipio,string $telefonoTienda,
		string $direccionTienda,int $idTienda) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "UPDATE Tiendas SET Nombre = ?, IdCiudad = ?,Telefono = ?,Direccion = ? WHERE IdTienda = ?;";
        $boolTienda = false;
        try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nombreTienda,PDO::PARAM_STR);
            $stmt->bindParam(2,$municipio,PDO::PARAM_INT);
            $stmt->bindParam(3,$telefonoTienda,PDO::PARAM_STR);
            $stmt->bindParam(4,$direccionTienda,PDO::PARAM_STR);
            $stmt->bindParam(5,$idTienda,PDO::PARAM_STR);
            if($stmt->execute()){
                $boolTienda = true;
            }
            $con->commit();
            return $boolTienda;
        }catch(PDOException $ex){
          throw $ex;
          $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo

	public function insertarTiendaModificadaAdministrador(array $subirFoto,string $nombreTienda,string $telefonoTienda,
		string $direccionTienda,int $idTienda) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "UPDATE Tiendas SET Nombre = ?,Telefono = ?,Direccion = ?,ImagenTienda = ? WHERE IdTienda = ?;";
        $boolTienda = false;
        try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nombreTienda,PDO::PARAM_STR);
            $stmt->bindParam(2,$telefonoTienda,PDO::PARAM_STR);
            $stmt->bindParam(3,$direccionTienda,PDO::PARAM_STR);
            ////PARA LA imagen
            $fotoF = $subirFoto['imagen'];//string
            $tipo = $subirFoto['tipo'];//string
            $rutaImagenSubida = 'Imagenes/ImagenesTienda/'.$fotoF;
            if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
                $stmt->bindParam(4,$rutaImagenSubida,PDO::PARAM_STR);
            }
            $stmt->bindParam(5,$idTienda,PDO::PARAM_STR);
            if($stmt->execute()){
                $boolTienda = true;
            }
            $con->commit();
            return $boolTienda;
        }catch(PDOException $ex){
          throw $ex;
          $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo


	public function insertarTiendaModificadaAdministradorSinFoto(string $nombreTienda,string $telefonoTienda,
		string $direccionTienda,int $idTienda) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "UPDATE Tiendas SET Nombre = ?,Telefono = ?,Direccion = ? WHERE IdTienda = ?;";
        $boolTienda = false;
        try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nombreTienda,PDO::PARAM_STR);
            $stmt->bindParam(2,$telefonoTienda,PDO::PARAM_STR);
            $stmt->bindParam(3,$direccionTienda,PDO::PARAM_STR);
            $stmt->bindParam(4,$idTienda,PDO::PARAM_STR);
            if($stmt->execute()){
                $boolTienda = true;
            }
            $con->commit();
            return $boolTienda;
        }catch(PDOException $ex){
          throw $ex;
          $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo

	public function insertarTienda(array $subirFoto,string $nombreTienda,int $municipio,string $telefonoTienda,
		string $direccionTienda, bool $activo) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "INSERT INTO Tiendas(Nombre,IdCiudad,Telefono,Direccion,ImagenTienda,Activo) VALUES(?,?,?,?,?,?);";
        $boolTienda = false;
        try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nombreTienda,PDO::PARAM_STR);
            $stmt->bindParam(2,$municipio,PDO::PARAM_STR);
            $stmt->bindParam(3,$telefonoTienda,PDO::PARAM_STR);
            $stmt->bindParam(4,$direccionTienda,PDO::PARAM_STR);
            ////PARA LA imagen
            $fotoF = $subirFoto['imagen'];//string
            $tipo = $subirFoto['tipo'];//string
            $rutaImagenSubida = 'Imagenes/ImagenesTienda/'.$fotoF;
            if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
                $stmt->bindParam(5,$rutaImagenSubida,PDO::PARAM_STR);
            }

						$stmt->bindParam(6,$activo,PDO::PARAM_STR);
            if($stmt->execute()){
                $boolTienda = true;
            }

            $con->commit();
            return $boolTienda;
        }catch(PDOException $ex){
          throw $ex;
          $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo

	public function devolverExistenciasLibroPorTienda(array $tiendas,int $idLibro) :array{
				$arrayTiendaCantidadLibro = [];
				include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
				$sql = "SELECT Almacen.Stock FROM Almacen
								JOIN Ejemplares ON Ejemplares.IdEjemplar = Almacen.IdEjemplar
								JOIN Libros ON Libros.IdLibro = Ejemplares.IdLibro
								WHERE Almacen.IdTienda = ? AND Libros.IdLibro = ?";
				foreach ($tiendas as $key => $value) {
						$idTienda  = (int)$value->getIdTienda();
						$con = (new ConexionBaseDatos)->getConexion();
						$stmt = $con->prepare($sql);
						$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
						$stmt->bindParam(2,$idLibro,PDO::PARAM_INT);
						$stmt->execute();
						while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
							$arrayTiendaCantidadLibro[] = $row['Stock'];
						}
						$stmt =null;
						$con=null;
				}
				return $arrayTiendaCantidadLibro;
	}//fin metodo

	public function devolverNumerosEjemplaresActuales() :int{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$numeroEjemplares= 0;
			$sql = "SELECT COUNT(Ejemplares.IdEjemplar) AS CUENTA FROM Ejemplares;";
			$stmt = $con->prepare($sql);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$numeroEjemplares = $row['CUENTA'];
			}
			$con = null;
			$stmt = null;
			return $numeroEjemplares;
	}//fin metodo

	public function devolverUltimoIdTienda() :int{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$id= 0;
			$sql = "SELECT TOP 1 IdTienda AS ULTIMO_ID FROM Tiendas ORDER BY IdTienda DESC;";
			$stmt = $con->prepare($sql);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$id = $row['ULTIMO_ID'];
			}
			$con = null;
			$stmt = null;
			return $id;
	}//fin metodo

	public function insertarCatalogoNuevaTienda(int $idUltimaTiendaInsertada,int $numeroEjemplares) :bool{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';//EXEC insertarStockCeroNuevaTienda 1,7 //IdEjemplar,IdTienda //430
			$boolStock= false;
			for ($i=1; $i < ($numeroEjemplares+1); $i++) {
						$con = (new ConexionBaseDatos)->getConexion();
						$sql = "EXEC insertarStockCeroNuevaTienda ?,? ;";
						$boolStock= false; //lo iniciamos en el bucle a false para comprobar que hace bien todas las vueltas
						try{
									$con->beginTransaction();
									$stmt = $con->prepare($sql);
									$stmt->bindParam(1,$i,PDO::PARAM_INT);
									$stmt->bindParam(2,$idUltimaTiendaInsertada,PDO::PARAM_INT);
							if($stmt->execute()){
									$boolStock= true;
							}
							$con->commit();
						}catch(PDOException  $eX ){
								echo "Error: ".$eX;
								$con->rollback();
						}finally {
								$con = null;
								$stmt = null;
						}

			}
			return $boolStock;
	}//fin metodo

	public function sacarIdTiendaAdm(string $email) :int{
			$sql = "SELECT Tiendas.IdTienda FROM AdministradorTienda
					JOIN Tiendas ON Tiendas.IdTienda = AdministradorTienda.IdTienda
					WHERE AdministradorTienda.Email = ?;";
					include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$ids= 0;
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$email,PDO::PARAM_STR);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$ids = $row['IdTienda'];
			}
			$con = null;
			$stmt = null;
			return $ids;
	}//fin metodo

	public function devolverNumeroAdministradoresTienda(int $sacarIdTiendaAdm) :int{
			$sql = "SELECT  COUNT(Tiendas.IdTienda) AS  CUENTA  FROM AdministradorTienda
									JOIN Tiendas ON Tiendas.IdTienda = AdministradorTienda.IdTienda
									WHERE Tiendas.IdTienda = ?;";
					include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$ids= 0;
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$sacarIdTiendaAdm,PDO::PARAM_STR);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$ids = $row['CUENTA'];
			}
			$con = null;
			$stmt = null;
			return $ids;
	}//fin metodo

	public function activarTiendaAsignada(int $idTienda) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolT = true;
		$sql = "UPDATE Tiendas SET Activo =  ? WHERE IdTienda = ?;";
		$boolTienda = false;
		try{
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$boolT,PDO::PARAM_STR);
				$stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
				if($stmt->execute()){
						$boolTienda = true;
				}
				$con->commit();
				return $boolTienda;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$con = null;
			$stmt = null;
		}
	}

	public function desactivarTiendaAsignada(int $idTienda) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolT = false;
		$sql = "UPDATE Tiendas SET Activo =  ? WHERE IdTienda = ?;";
		$boolTienda = false;
		try{
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$boolT,PDO::PARAM_STR);
				$stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
				if($stmt->execute()){
						$boolTienda = true;
				}
				$con->commit();
				return $boolTienda;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$con = null;
			$stmt = null;
		}
	}

}//fin clase
